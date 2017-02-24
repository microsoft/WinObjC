// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Graphics.DirectX.Direct3D11.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"
#include "Windows.Storage.Streams.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapBuffer> : produce_base<D, Windows::Graphics::Imaging::IBitmapBuffer>
{
    HRESULT __stdcall abi_GetPlaneCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetPlaneCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPlaneDescription(int32_t index, impl::abi_arg_out<Windows::Graphics::Imaging::BitmapPlaneDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetPlaneDescription(index));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapCodecInformation> : produce_base<D, Windows::Graphics::Imaging::IBitmapCodecInformation>
{
    HRESULT __stdcall get_CodecId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CodecId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileExtensions(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileExtensions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MimeTypes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MimeTypes());
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
struct produce<D, Windows::Graphics::Imaging::IBitmapDecoder> : produce_base<D, Windows::Graphics::Imaging::IBitmapDecoder>
{
    HRESULT __stdcall get_BitmapContainerProperties(impl::abi_arg_out<Windows::Graphics::Imaging::IBitmapPropertiesView> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapContainerProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DecoderInformation(impl::abi_arg_out<Windows::Graphics::Imaging::IBitmapCodecInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecoderInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPreviewAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetPreviewAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFrameAsync(uint32_t frameIndex, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapFrame>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetFrameAsync(frameIndex));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapDecoderStatics> : produce_base<D, Windows::Graphics::Imaging::IBitmapDecoderStatics>
{
    HRESULT __stdcall get_BmpDecoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BmpDecoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JpegDecoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JpegDecoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PngDecoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PngDecoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TiffDecoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TiffDecoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GifDecoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GifDecoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JpegXRDecoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JpegXRDecoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IcoDecoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IcoDecoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDecoderInformationEnumerator(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation>> decoderInformationEnumerator) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *decoderInformationEnumerator = detach_abi(this->shim().GetDecoderInformationEnumerator());
            return S_OK;
        }
        catch (...)
        {
            *decoderInformationEnumerator = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().CreateAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithIdAsync(GUID decoderId, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().CreateAsync(decoderId, *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapEncoder> : produce_base<D, Windows::Graphics::Imaging::IBitmapEncoder>
{
    HRESULT __stdcall get_EncoderInformation(impl::abi_arg_out<Windows::Graphics::Imaging::IBitmapCodecInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncoderInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapProperties(impl::abi_arg_out<Windows::Graphics::Imaging::IBitmapProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapContainerProperties(impl::abi_arg_out<Windows::Graphics::Imaging::IBitmapProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapContainerProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsThumbnailGenerated(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsThumbnailGenerated());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsThumbnailGenerated(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsThumbnailGenerated(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GeneratedThumbnailWidth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GeneratedThumbnailWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GeneratedThumbnailWidth(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GeneratedThumbnailWidth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GeneratedThumbnailHeight(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GeneratedThumbnailHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GeneratedThumbnailHeight(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GeneratedThumbnailHeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapTransform(impl::abi_arg_out<Windows::Graphics::Imaging::IBitmapTransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapTransform());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPixelData(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, uint32_t width, uint32_t height, double dpiX, double dpiY, uint32_t __pixelsSize, impl::abi_arg_in<uint8_t> * pixels) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPixelData(pixelFormat, alphaMode, width, height, dpiX, dpiY, array_view<const uint8_t>(pixels, pixels + __pixelsSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GoToNextFrameAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GoToNextFrameAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GoToNextFrameWithEncodingOptionsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>>> encodingOptions, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GoToNextFrameAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> *>(&encodingOptions)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FlushAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().FlushAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapEncoderStatics> : produce_base<D, Windows::Graphics::Imaging::IBitmapEncoderStatics>
{
    HRESULT __stdcall get_BmpEncoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BmpEncoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JpegEncoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JpegEncoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PngEncoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PngEncoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TiffEncoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TiffEncoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GifEncoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GifEncoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JpegXREncoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().JpegXREncoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEncoderInformationEnumerator(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation>> encoderInformationEnumerator) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *encoderInformationEnumerator = detach_abi(this->shim().GetEncoderInformationEnumerator());
            return S_OK;
        }
        catch (...)
        {
            *encoderInformationEnumerator = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAsync(GUID encoderId, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().CreateAsync(encoderId, *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithEncodingOptionsAsync(GUID encoderId, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>>> encodingOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().CreateAsync(encoderId, *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> *>(&encodingOptions)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateForTranscodingAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapDecoder> bitmapDecoder, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().CreateForTranscodingAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream), *reinterpret_cast<const Windows::Graphics::Imaging::BitmapDecoder *>(&bitmapDecoder)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateForInPlacePropertyEncodingAsync(impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapDecoder> bitmapDecoder, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().CreateForInPlacePropertyEncodingAsync(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapDecoder *>(&bitmapDecoder)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap> : produce_base<D, Windows::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap>
{
    HRESULT __stdcall abi_SetSoftwareBitmap(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> bitmap) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSoftwareBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&bitmap));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapFrame> : produce_base<D, Windows::Graphics::Imaging::IBitmapFrame>
{
    HRESULT __stdcall abi_GetThumbnailAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetThumbnailAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapProperties(impl::abi_arg_out<Windows::Graphics::Imaging::IBitmapPropertiesView> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapPixelFormat(Windows::Graphics::Imaging::BitmapPixelFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapPixelFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapAlphaMode(Windows::Graphics::Imaging::BitmapAlphaMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapAlphaMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DpiX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DpiX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DpiY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DpiY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PixelWidth(uint32_t * value) noexcept override
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

    HRESULT __stdcall get_PixelHeight(uint32_t * value) noexcept override
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

    HRESULT __stdcall get_OrientedPixelWidth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OrientedPixelWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OrientedPixelHeight(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OrientedPixelHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPixelDataAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetPixelDataAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPixelDataTransformedAsync(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapTransform> transform, Windows::Graphics::Imaging::ExifOrientationMode exifOrientationMode, Windows::Graphics::Imaging::ColorManagementMode colorManagementMode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetPixelDataAsync(pixelFormat, alphaMode, *reinterpret_cast<const Windows::Graphics::Imaging::BitmapTransform *>(&transform), exifOrientationMode, colorManagementMode));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap> : produce_base<D, Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>
{
    HRESULT __stdcall abi_GetSoftwareBitmapAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetSoftwareBitmapAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSoftwareBitmapConvertedAsync(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetSoftwareBitmapAsync(pixelFormat, alphaMode));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSoftwareBitmapTransformedAsync(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, impl::abi_arg_in<Windows::Graphics::Imaging::IBitmapTransform> transform, Windows::Graphics::Imaging::ExifOrientationMode exifOrientationMode, Windows::Graphics::Imaging::ColorManagementMode colorManagementMode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetSoftwareBitmapAsync(pixelFormat, alphaMode, *reinterpret_cast<const Windows::Graphics::Imaging::BitmapTransform *>(&transform), exifOrientationMode, colorManagementMode));
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
struct produce<D, Windows::Graphics::Imaging::IBitmapProperties> : produce_base<D, Windows::Graphics::Imaging::IBitmapProperties>
{
    HRESULT __stdcall abi_SetPropertiesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>>> propertiesToSet, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SetPropertiesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> *>(&propertiesToSet)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapPropertiesView> : produce_base<D, Windows::Graphics::Imaging::IBitmapPropertiesView>
{
    HRESULT __stdcall abi_GetPropertiesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> propertiesToRetrieve, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapPropertySet>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetPropertiesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&propertiesToRetrieve)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapTransform> : produce_base<D, Windows::Graphics::Imaging::IBitmapTransform>
{
    HRESULT __stdcall get_ScaledWidth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaledWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScaledWidth(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaledWidth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaledHeight(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScaledHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScaledHeight(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScaledHeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InterpolationMode(Windows::Graphics::Imaging::BitmapInterpolationMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterpolationMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InterpolationMode(Windows::Graphics::Imaging::BitmapInterpolationMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InterpolationMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Flip(Windows::Graphics::Imaging::BitmapFlip * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Flip());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Flip(Windows::Graphics::Imaging::BitmapFlip value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Flip(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rotation(Windows::Graphics::Imaging::BitmapRotation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rotation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Rotation(Windows::Graphics::Imaging::BitmapRotation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rotation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bounds(impl::abi_arg_out<Windows::Graphics::Imaging::BitmapBounds> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bounds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Bounds(impl::abi_arg_in<Windows::Graphics::Imaging::BitmapBounds> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Bounds(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapBounds *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapTypedValue> : produce_base<D, Windows::Graphics::Imaging::IBitmapTypedValue>
{
    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(Windows::Foundation::PropertyType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IBitmapTypedValueFactory> : produce_base<D, Windows::Graphics::Imaging::IBitmapTypedValueFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::IInspectable> value, Windows::Foundation::PropertyType type, impl::abi_arg_out<Windows::Graphics::Imaging::IBitmapTypedValue> bitmapTypedValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *bitmapTypedValue = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value), type));
            return S_OK;
        }
        catch (...)
        {
            *bitmapTypedValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::IPixelDataProvider> : produce_base<D, Windows::Graphics::Imaging::IPixelDataProvider>
{
    HRESULT __stdcall abi_DetachPixelData(uint32_t * __pixelDataSize, impl::abi_arg_out<uint8_t> * pixelData) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__pixelDataSize, *pixelData) = detach_abi(this->shim().DetachPixelData());
            return S_OK;
        }
        catch (...)
        {
            *__pixelDataSize = 0;
            *pixelData = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Imaging::ISoftwareBitmap> : produce_base<D, Windows::Graphics::Imaging::ISoftwareBitmap>
{
    HRESULT __stdcall get_BitmapPixelFormat(Windows::Graphics::Imaging::BitmapPixelFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapPixelFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapAlphaMode(Windows::Graphics::Imaging::BitmapAlphaMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapAlphaMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_IsReadOnly(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsReadOnly());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DpiX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DpiX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DpiX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DpiX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DpiY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DpiY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DpiY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DpiY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LockBuffer(Windows::Graphics::Imaging::BitmapBufferAccessMode mode, impl::abi_arg_out<Windows::Graphics::Imaging::IBitmapBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LockBuffer(mode));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyTo(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> bitmap) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyTo(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&bitmap));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyFromBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyFromBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyToBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyToBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetReadOnlyView(impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetReadOnlyView());
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
struct produce<D, Windows::Graphics::Imaging::ISoftwareBitmapFactory> : produce_base<D, Windows::Graphics::Imaging::ISoftwareBitmapFactory>
{
    HRESULT __stdcall abi_Create(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(format, width, height));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithAlpha(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha, impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithAlpha(format, width, height, alpha));
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
struct produce<D, Windows::Graphics::Imaging::ISoftwareBitmapStatics> : produce_base<D, Windows::Graphics::Imaging::ISoftwareBitmapStatics>
{
    HRESULT __stdcall abi_Copy(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> source, impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Copy(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&source)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Convert(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> source, Windows::Graphics::Imaging::BitmapPixelFormat format, impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Convert(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&source), format));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertWithAlpha(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> source, Windows::Graphics::Imaging::BitmapPixelFormat format, Windows::Graphics::Imaging::BitmapAlphaMode alpha, impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Convert(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&source), format, alpha));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCopyFromBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> source, Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateCopyFromBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&source), format, width, height));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCopyWithAlphaFromBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> source, Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha, impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateCopyFromBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&source), format, width, height, alpha));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCopyFromSurfaceAsync(impl::abi_arg_in<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> surface, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateCopyFromSurfaceAsync(*reinterpret_cast<const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface *>(&surface)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCopyWithAlphaFromSurfaceAsync(impl::abi_arg_in<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> surface, Windows::Graphics::Imaging::BitmapAlphaMode alpha, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateCopyFromSurfaceAsync(*reinterpret_cast<const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface *>(&surface), alpha));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Graphics::Imaging {

template <typename D> uint32_t impl_IBitmapTransform<D>::ScaledWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBitmapTransform)->get_ScaledWidth(&value));
    return value;
}

template <typename D> void impl_IBitmapTransform<D>::ScaledWidth(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IBitmapTransform)->put_ScaledWidth(value));
}

template <typename D> uint32_t impl_IBitmapTransform<D>::ScaledHeight() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBitmapTransform)->get_ScaledHeight(&value));
    return value;
}

template <typename D> void impl_IBitmapTransform<D>::ScaledHeight(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IBitmapTransform)->put_ScaledHeight(value));
}

template <typename D> Windows::Graphics::Imaging::BitmapInterpolationMode impl_IBitmapTransform<D>::InterpolationMode() const
{
    Windows::Graphics::Imaging::BitmapInterpolationMode value {};
    check_hresult(WINRT_SHIM(IBitmapTransform)->get_InterpolationMode(&value));
    return value;
}

template <typename D> void impl_IBitmapTransform<D>::InterpolationMode(Windows::Graphics::Imaging::BitmapInterpolationMode value) const
{
    check_hresult(WINRT_SHIM(IBitmapTransform)->put_InterpolationMode(value));
}

template <typename D> Windows::Graphics::Imaging::BitmapFlip impl_IBitmapTransform<D>::Flip() const
{
    Windows::Graphics::Imaging::BitmapFlip value {};
    check_hresult(WINRT_SHIM(IBitmapTransform)->get_Flip(&value));
    return value;
}

template <typename D> void impl_IBitmapTransform<D>::Flip(Windows::Graphics::Imaging::BitmapFlip value) const
{
    check_hresult(WINRT_SHIM(IBitmapTransform)->put_Flip(value));
}

template <typename D> Windows::Graphics::Imaging::BitmapRotation impl_IBitmapTransform<D>::Rotation() const
{
    Windows::Graphics::Imaging::BitmapRotation value {};
    check_hresult(WINRT_SHIM(IBitmapTransform)->get_Rotation(&value));
    return value;
}

template <typename D> void impl_IBitmapTransform<D>::Rotation(Windows::Graphics::Imaging::BitmapRotation value) const
{
    check_hresult(WINRT_SHIM(IBitmapTransform)->put_Rotation(value));
}

template <typename D> Windows::Graphics::Imaging::BitmapBounds impl_IBitmapTransform<D>::Bounds() const
{
    Windows::Graphics::Imaging::BitmapBounds value {};
    check_hresult(WINRT_SHIM(IBitmapTransform)->get_Bounds(put_abi(value)));
    return value;
}

template <typename D> void impl_IBitmapTransform<D>::Bounds(const Windows::Graphics::Imaging::BitmapBounds & value) const
{
    check_hresult(WINRT_SHIM(IBitmapTransform)->put_Bounds(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IBitmapTypedValue<D>::Value() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IBitmapTypedValue)->get_Value(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::PropertyType impl_IBitmapTypedValue<D>::Type() const
{
    Windows::Foundation::PropertyType value {};
    check_hresult(WINRT_SHIM(IBitmapTypedValue)->get_Type(&value));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapTypedValue impl_IBitmapTypedValueFactory<D>::Create(const Windows::Foundation::IInspectable & value, Windows::Foundation::PropertyType type) const
{
    Windows::Graphics::Imaging::BitmapTypedValue bitmapTypedValue { nullptr };
    check_hresult(WINRT_SHIM(IBitmapTypedValueFactory)->abi_Create(get_abi(value), type, put_abi(bitmapTypedValue)));
    return bitmapTypedValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapPropertySet> impl_IBitmapPropertiesView<D>::GetPropertiesAsync(iterable<hstring> propertiesToRetrieve) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapPropertySet> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapPropertiesView)->abi_GetPropertiesAsync(get_abi(propertiesToRetrieve), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IBitmapProperties<D>::SetPropertiesAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> propertiesToSet) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapProperties)->abi_SetPropertiesAsync(get_abi(propertiesToSet), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> com_array<uint8_t> impl_IPixelDataProvider<D>::DetachPixelData() const
{
    com_array<uint8_t> pixelData {};
    check_hresult(WINRT_SHIM(IPixelDataProvider)->abi_DetachPixelData(impl::put_size_abi(pixelData), put_abi(pixelData)));
    return pixelData;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> impl_IBitmapFrame<D>::GetThumbnailAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapFrame)->abi_GetThumbnailAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Graphics::Imaging::BitmapPropertiesView impl_IBitmapFrame<D>::BitmapProperties() const
{
    Windows::Graphics::Imaging::BitmapPropertiesView value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapFrame)->get_BitmapProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapPixelFormat impl_IBitmapFrame<D>::BitmapPixelFormat() const
{
    Windows::Graphics::Imaging::BitmapPixelFormat value {};
    check_hresult(WINRT_SHIM(IBitmapFrame)->get_BitmapPixelFormat(&value));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapAlphaMode impl_IBitmapFrame<D>::BitmapAlphaMode() const
{
    Windows::Graphics::Imaging::BitmapAlphaMode value {};
    check_hresult(WINRT_SHIM(IBitmapFrame)->get_BitmapAlphaMode(&value));
    return value;
}

template <typename D> double impl_IBitmapFrame<D>::DpiX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IBitmapFrame)->get_DpiX(&value));
    return value;
}

template <typename D> double impl_IBitmapFrame<D>::DpiY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IBitmapFrame)->get_DpiY(&value));
    return value;
}

template <typename D> uint32_t impl_IBitmapFrame<D>::PixelWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBitmapFrame)->get_PixelWidth(&value));
    return value;
}

template <typename D> uint32_t impl_IBitmapFrame<D>::PixelHeight() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBitmapFrame)->get_PixelHeight(&value));
    return value;
}

template <typename D> uint32_t impl_IBitmapFrame<D>::OrientedPixelWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBitmapFrame)->get_OrientedPixelWidth(&value));
    return value;
}

template <typename D> uint32_t impl_IBitmapFrame<D>::OrientedPixelHeight() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBitmapFrame)->get_OrientedPixelHeight(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider> impl_IBitmapFrame<D>::GetPixelDataAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapFrame)->abi_GetPixelDataAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider> impl_IBitmapFrame<D>::GetPixelDataAsync(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, const Windows::Graphics::Imaging::BitmapTransform & transform, Windows::Graphics::Imaging::ExifOrientationMode exifOrientationMode, Windows::Graphics::Imaging::ColorManagementMode colorManagementMode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapFrame)->abi_GetPixelDataTransformedAsync(pixelFormat, alphaMode, get_abi(transform), exifOrientationMode, colorManagementMode, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> impl_IBitmapFrameWithSoftwareBitmap<D>::GetSoftwareBitmapAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> value;
    check_hresult(WINRT_SHIM(IBitmapFrameWithSoftwareBitmap)->abi_GetSoftwareBitmapAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> impl_IBitmapFrameWithSoftwareBitmap<D>::GetSoftwareBitmapAsync(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> value;
    check_hresult(WINRT_SHIM(IBitmapFrameWithSoftwareBitmap)->abi_GetSoftwareBitmapConvertedAsync(pixelFormat, alphaMode, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> impl_IBitmapFrameWithSoftwareBitmap<D>::GetSoftwareBitmapAsync(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, const Windows::Graphics::Imaging::BitmapTransform & transform, Windows::Graphics::Imaging::ExifOrientationMode exifOrientationMode, Windows::Graphics::Imaging::ColorManagementMode colorManagementMode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> value;
    check_hresult(WINRT_SHIM(IBitmapFrameWithSoftwareBitmap)->abi_GetSoftwareBitmapTransformedAsync(pixelFormat, alphaMode, get_abi(transform), exifOrientationMode, colorManagementMode, put_abi(value)));
    return value;
}

template <typename D> GUID impl_IBitmapCodecInformation<D>::CodecId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapCodecInformation)->get_CodecId(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IBitmapCodecInformation<D>::FileExtensions() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IBitmapCodecInformation)->get_FileExtensions(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IBitmapCodecInformation<D>::FriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBitmapCodecInformation)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IBitmapCodecInformation<D>::MimeTypes() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IBitmapCodecInformation)->get_MimeTypes(put_abi(value)));
    return value;
}

template <typename D> GUID impl_IBitmapDecoderStatics<D>::BmpDecoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapDecoderStatics)->get_BmpDecoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapDecoderStatics<D>::JpegDecoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapDecoderStatics)->get_JpegDecoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapDecoderStatics<D>::PngDecoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapDecoderStatics)->get_PngDecoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapDecoderStatics<D>::TiffDecoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapDecoderStatics)->get_TiffDecoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapDecoderStatics<D>::GifDecoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapDecoderStatics)->get_GifDecoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapDecoderStatics<D>::JpegXRDecoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapDecoderStatics)->get_JpegXRDecoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapDecoderStatics<D>::IcoDecoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapDecoderStatics)->get_IcoDecoderId(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> impl_IBitmapDecoderStatics<D>::GetDecoderInformationEnumerator() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> decoderInformationEnumerator;
    check_hresult(WINRT_SHIM(IBitmapDecoderStatics)->abi_GetDecoderInformationEnumerator(put_abi(decoderInformationEnumerator)));
    return decoderInformationEnumerator;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> impl_IBitmapDecoderStatics<D>::CreateAsync(const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapDecoderStatics)->abi_CreateAsync(get_abi(stream), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> impl_IBitmapDecoderStatics<D>::CreateAsync(GUID decoderId, const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapDecoderStatics)->abi_CreateWithIdAsync(decoderId, get_abi(stream), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Graphics::Imaging::BitmapPropertiesView impl_IBitmapDecoder<D>::BitmapContainerProperties() const
{
    Windows::Graphics::Imaging::BitmapPropertiesView value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapDecoder)->get_BitmapContainerProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapCodecInformation impl_IBitmapDecoder<D>::DecoderInformation() const
{
    Windows::Graphics::Imaging::BitmapCodecInformation value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapDecoder)->get_DecoderInformation(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IBitmapDecoder<D>::FrameCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBitmapDecoder)->get_FrameCount(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> impl_IBitmapDecoder<D>::GetPreviewAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapDecoder)->abi_GetPreviewAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapFrame> impl_IBitmapDecoder<D>::GetFrameAsync(uint32_t frameIndex) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapFrame> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapDecoder)->abi_GetFrameAsync(frameIndex, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> GUID impl_IBitmapEncoderStatics<D>::BmpEncoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->get_BmpEncoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapEncoderStatics<D>::JpegEncoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->get_JpegEncoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapEncoderStatics<D>::PngEncoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->get_PngEncoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapEncoderStatics<D>::TiffEncoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->get_TiffEncoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapEncoderStatics<D>::GifEncoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->get_GifEncoderId(&value));
    return value;
}

template <typename D> GUID impl_IBitmapEncoderStatics<D>::JpegXREncoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->get_JpegXREncoderId(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> impl_IBitmapEncoderStatics<D>::GetEncoderInformationEnumerator() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> encoderInformationEnumerator;
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->abi_GetEncoderInformationEnumerator(put_abi(encoderInformationEnumerator)));
    return encoderInformationEnumerator;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> impl_IBitmapEncoderStatics<D>::CreateAsync(GUID encoderId, const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->abi_CreateAsync(encoderId, get_abi(stream), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> impl_IBitmapEncoderStatics<D>::CreateAsync(GUID encoderId, const Windows::Storage::Streams::IRandomAccessStream & stream, iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> encodingOptions) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->abi_CreateWithEncodingOptionsAsync(encoderId, get_abi(stream), get_abi(encodingOptions), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> impl_IBitmapEncoderStatics<D>::CreateForTranscodingAsync(const Windows::Storage::Streams::IRandomAccessStream & stream, const Windows::Graphics::Imaging::BitmapDecoder & bitmapDecoder) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->abi_CreateForTranscodingAsync(get_abi(stream), get_abi(bitmapDecoder), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> impl_IBitmapEncoderStatics<D>::CreateForInPlacePropertyEncodingAsync(const Windows::Graphics::Imaging::BitmapDecoder & bitmapDecoder) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapEncoderStatics)->abi_CreateForInPlacePropertyEncodingAsync(get_abi(bitmapDecoder), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Graphics::Imaging::BitmapCodecInformation impl_IBitmapEncoder<D>::EncoderInformation() const
{
    Windows::Graphics::Imaging::BitmapCodecInformation value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapEncoder)->get_EncoderInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapProperties impl_IBitmapEncoder<D>::BitmapProperties() const
{
    Windows::Graphics::Imaging::BitmapProperties value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapEncoder)->get_BitmapProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapProperties impl_IBitmapEncoder<D>::BitmapContainerProperties() const
{
    Windows::Graphics::Imaging::BitmapProperties value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapEncoder)->get_BitmapContainerProperties(put_abi(value)));
    return value;
}

template <typename D> bool impl_IBitmapEncoder<D>::IsThumbnailGenerated() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBitmapEncoder)->get_IsThumbnailGenerated(&value));
    return value;
}

template <typename D> void impl_IBitmapEncoder<D>::IsThumbnailGenerated(bool value) const
{
    check_hresult(WINRT_SHIM(IBitmapEncoder)->put_IsThumbnailGenerated(value));
}

template <typename D> uint32_t impl_IBitmapEncoder<D>::GeneratedThumbnailWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBitmapEncoder)->get_GeneratedThumbnailWidth(&value));
    return value;
}

template <typename D> void impl_IBitmapEncoder<D>::GeneratedThumbnailWidth(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IBitmapEncoder)->put_GeneratedThumbnailWidth(value));
}

template <typename D> uint32_t impl_IBitmapEncoder<D>::GeneratedThumbnailHeight() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBitmapEncoder)->get_GeneratedThumbnailHeight(&value));
    return value;
}

template <typename D> void impl_IBitmapEncoder<D>::GeneratedThumbnailHeight(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IBitmapEncoder)->put_GeneratedThumbnailHeight(value));
}

template <typename D> Windows::Graphics::Imaging::BitmapTransform impl_IBitmapEncoder<D>::BitmapTransform() const
{
    Windows::Graphics::Imaging::BitmapTransform value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapEncoder)->get_BitmapTransform(put_abi(value)));
    return value;
}

template <typename D> void impl_IBitmapEncoder<D>::SetPixelData(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, uint32_t width, uint32_t height, double dpiX, double dpiY, array_view<const uint8_t> pixels) const
{
    check_hresult(WINRT_SHIM(IBitmapEncoder)->abi_SetPixelData(pixelFormat, alphaMode, width, height, dpiX, dpiY, pixels.size(), get_abi(pixels)));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IBitmapEncoder<D>::GoToNextFrameAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapEncoder)->abi_GoToNextFrameAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IBitmapEncoder<D>::GoToNextFrameAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> encodingOptions) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapEncoder)->abi_GoToNextFrameWithEncodingOptionsAsync(get_abi(encodingOptions), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IBitmapEncoder<D>::FlushAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IBitmapEncoder)->abi_FlushAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> void impl_IBitmapEncoderWithSoftwareBitmap<D>::SetSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & bitmap) const
{
    check_hresult(WINRT_SHIM(IBitmapEncoderWithSoftwareBitmap)->abi_SetSoftwareBitmap(get_abi(bitmap)));
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_ISoftwareBitmapFactory<D>::Create(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height) const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(ISoftwareBitmapFactory)->abi_Create(format, width, height, put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_ISoftwareBitmapFactory<D>::CreateWithAlpha(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(ISoftwareBitmapFactory)->abi_CreateWithAlpha(format, width, height, alpha, put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_ISoftwareBitmapStatics<D>::Copy(const Windows::Graphics::Imaging::SoftwareBitmap & source) const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(ISoftwareBitmapStatics)->abi_Copy(get_abi(source), put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_ISoftwareBitmapStatics<D>::Convert(const Windows::Graphics::Imaging::SoftwareBitmap & source, Windows::Graphics::Imaging::BitmapPixelFormat format) const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(ISoftwareBitmapStatics)->abi_Convert(get_abi(source), format, put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_ISoftwareBitmapStatics<D>::Convert(const Windows::Graphics::Imaging::SoftwareBitmap & source, Windows::Graphics::Imaging::BitmapPixelFormat format, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(ISoftwareBitmapStatics)->abi_ConvertWithAlpha(get_abi(source), format, alpha, put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_ISoftwareBitmapStatics<D>::CreateCopyFromBuffer(const Windows::Storage::Streams::IBuffer & source, Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height) const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(ISoftwareBitmapStatics)->abi_CreateCopyFromBuffer(get_abi(source), format, width, height, put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_ISoftwareBitmapStatics<D>::CreateCopyFromBuffer(const Windows::Storage::Streams::IBuffer & source, Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(ISoftwareBitmapStatics)->abi_CreateCopyWithAlphaFromBuffer(get_abi(source), format, width, height, alpha, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> impl_ISoftwareBitmapStatics<D>::CreateCopyFromSurfaceAsync(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> value;
    check_hresult(WINRT_SHIM(ISoftwareBitmapStatics)->abi_CreateCopyFromSurfaceAsync(get_abi(surface), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> impl_ISoftwareBitmapStatics<D>::CreateCopyFromSurfaceAsync(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> value;
    check_hresult(WINRT_SHIM(ISoftwareBitmapStatics)->abi_CreateCopyWithAlphaFromSurfaceAsync(get_abi(surface), alpha, put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapPixelFormat impl_ISoftwareBitmap<D>::BitmapPixelFormat() const
{
    Windows::Graphics::Imaging::BitmapPixelFormat value {};
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->get_BitmapPixelFormat(&value));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapAlphaMode impl_ISoftwareBitmap<D>::BitmapAlphaMode() const
{
    Windows::Graphics::Imaging::BitmapAlphaMode value {};
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->get_BitmapAlphaMode(&value));
    return value;
}

template <typename D> int32_t impl_ISoftwareBitmap<D>::PixelWidth() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->get_PixelWidth(&value));
    return value;
}

template <typename D> int32_t impl_ISoftwareBitmap<D>::PixelHeight() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->get_PixelHeight(&value));
    return value;
}

template <typename D> bool impl_ISoftwareBitmap<D>::IsReadOnly() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->get_IsReadOnly(&value));
    return value;
}

template <typename D> void impl_ISoftwareBitmap<D>::DpiX(double value) const
{
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->put_DpiX(value));
}

template <typename D> double impl_ISoftwareBitmap<D>::DpiX() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->get_DpiX(&value));
    return value;
}

template <typename D> void impl_ISoftwareBitmap<D>::DpiY(double value) const
{
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->put_DpiY(value));
}

template <typename D> double impl_ISoftwareBitmap<D>::DpiY() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->get_DpiY(&value));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapBuffer impl_ISoftwareBitmap<D>::LockBuffer(Windows::Graphics::Imaging::BitmapBufferAccessMode mode) const
{
    Windows::Graphics::Imaging::BitmapBuffer value { nullptr };
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->abi_LockBuffer(mode, put_abi(value)));
    return value;
}

template <typename D> void impl_ISoftwareBitmap<D>::CopyTo(const Windows::Graphics::Imaging::SoftwareBitmap & bitmap) const
{
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->abi_CopyTo(get_abi(bitmap)));
}

template <typename D> void impl_ISoftwareBitmap<D>::CopyFromBuffer(const Windows::Storage::Streams::IBuffer & buffer) const
{
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->abi_CopyFromBuffer(get_abi(buffer)));
}

template <typename D> void impl_ISoftwareBitmap<D>::CopyToBuffer(const Windows::Storage::Streams::IBuffer & buffer) const
{
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->abi_CopyToBuffer(get_abi(buffer)));
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_ISoftwareBitmap<D>::GetReadOnlyView() const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(ISoftwareBitmap)->abi_GetReadOnlyView(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IBitmapBuffer<D>::GetPlaneCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IBitmapBuffer)->abi_GetPlaneCount(&value));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapPlaneDescription impl_IBitmapBuffer<D>::GetPlaneDescription(int32_t index) const
{
    Windows::Graphics::Imaging::BitmapPlaneDescription value {};
    check_hresult(WINRT_SHIM(IBitmapBuffer)->abi_GetPlaneDescription(index, put_abi(value)));
    return value;
}

inline GUID BitmapDecoder::BmpDecoderId()
{
    return get_activation_factory<BitmapDecoder, IBitmapDecoderStatics>().BmpDecoderId();
}

inline GUID BitmapDecoder::JpegDecoderId()
{
    return get_activation_factory<BitmapDecoder, IBitmapDecoderStatics>().JpegDecoderId();
}

inline GUID BitmapDecoder::PngDecoderId()
{
    return get_activation_factory<BitmapDecoder, IBitmapDecoderStatics>().PngDecoderId();
}

inline GUID BitmapDecoder::TiffDecoderId()
{
    return get_activation_factory<BitmapDecoder, IBitmapDecoderStatics>().TiffDecoderId();
}

inline GUID BitmapDecoder::GifDecoderId()
{
    return get_activation_factory<BitmapDecoder, IBitmapDecoderStatics>().GifDecoderId();
}

inline GUID BitmapDecoder::JpegXRDecoderId()
{
    return get_activation_factory<BitmapDecoder, IBitmapDecoderStatics>().JpegXRDecoderId();
}

inline GUID BitmapDecoder::IcoDecoderId()
{
    return get_activation_factory<BitmapDecoder, IBitmapDecoderStatics>().IcoDecoderId();
}

inline Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> BitmapDecoder::GetDecoderInformationEnumerator()
{
    return get_activation_factory<BitmapDecoder, IBitmapDecoderStatics>().GetDecoderInformationEnumerator();
}

inline Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> BitmapDecoder::CreateAsync(const Windows::Storage::Streams::IRandomAccessStream & stream)
{
    return get_activation_factory<BitmapDecoder, IBitmapDecoderStatics>().CreateAsync(stream);
}

inline Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> BitmapDecoder::CreateAsync(GUID decoderId, const Windows::Storage::Streams::IRandomAccessStream & stream)
{
    return get_activation_factory<BitmapDecoder, IBitmapDecoderStatics>().CreateAsync(decoderId, stream);
}

inline GUID BitmapEncoder::BmpEncoderId()
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().BmpEncoderId();
}

inline GUID BitmapEncoder::JpegEncoderId()
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().JpegEncoderId();
}

inline GUID BitmapEncoder::PngEncoderId()
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().PngEncoderId();
}

inline GUID BitmapEncoder::TiffEncoderId()
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().TiffEncoderId();
}

inline GUID BitmapEncoder::GifEncoderId()
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().GifEncoderId();
}

inline GUID BitmapEncoder::JpegXREncoderId()
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().JpegXREncoderId();
}

inline Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> BitmapEncoder::GetEncoderInformationEnumerator()
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().GetEncoderInformationEnumerator();
}

inline Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> BitmapEncoder::CreateAsync(GUID encoderId, const Windows::Storage::Streams::IRandomAccessStream & stream)
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().CreateAsync(encoderId, stream);
}

inline Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> BitmapEncoder::CreateAsync(GUID encoderId, const Windows::Storage::Streams::IRandomAccessStream & stream, iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> encodingOptions)
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().CreateAsync(encoderId, stream, encodingOptions);
}

inline Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> BitmapEncoder::CreateForTranscodingAsync(const Windows::Storage::Streams::IRandomAccessStream & stream, const Windows::Graphics::Imaging::BitmapDecoder & bitmapDecoder)
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().CreateForTranscodingAsync(stream, bitmapDecoder);
}

inline Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> BitmapEncoder::CreateForInPlacePropertyEncodingAsync(const Windows::Graphics::Imaging::BitmapDecoder & bitmapDecoder)
{
    return get_activation_factory<BitmapEncoder, IBitmapEncoderStatics>().CreateForInPlacePropertyEncodingAsync(bitmapDecoder);
}

inline BitmapPropertySet::BitmapPropertySet() :
    BitmapPropertySet(activate_instance<BitmapPropertySet>())
{}

inline BitmapTransform::BitmapTransform() :
    BitmapTransform(activate_instance<BitmapTransform>())
{}

inline BitmapTypedValue::BitmapTypedValue(const Windows::Foundation::IInspectable & value, Windows::Foundation::PropertyType type) :
    BitmapTypedValue(get_activation_factory<BitmapTypedValue, IBitmapTypedValueFactory>().Create(value, type))
{}

inline SoftwareBitmap::SoftwareBitmap(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height) :
    SoftwareBitmap(get_activation_factory<SoftwareBitmap, ISoftwareBitmapFactory>().Create(format, width, height))
{}

inline SoftwareBitmap::SoftwareBitmap(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha) :
    SoftwareBitmap(get_activation_factory<SoftwareBitmap, ISoftwareBitmapFactory>().CreateWithAlpha(format, width, height, alpha))
{}

inline Windows::Graphics::Imaging::SoftwareBitmap SoftwareBitmap::Copy(const Windows::Graphics::Imaging::SoftwareBitmap & source)
{
    return get_activation_factory<SoftwareBitmap, ISoftwareBitmapStatics>().Copy(source);
}

inline Windows::Graphics::Imaging::SoftwareBitmap SoftwareBitmap::Convert(const Windows::Graphics::Imaging::SoftwareBitmap & source, Windows::Graphics::Imaging::BitmapPixelFormat format)
{
    return get_activation_factory<SoftwareBitmap, ISoftwareBitmapStatics>().Convert(source, format);
}

inline Windows::Graphics::Imaging::SoftwareBitmap SoftwareBitmap::Convert(const Windows::Graphics::Imaging::SoftwareBitmap & source, Windows::Graphics::Imaging::BitmapPixelFormat format, Windows::Graphics::Imaging::BitmapAlphaMode alpha)
{
    return get_activation_factory<SoftwareBitmap, ISoftwareBitmapStatics>().Convert(source, format, alpha);
}

inline Windows::Graphics::Imaging::SoftwareBitmap SoftwareBitmap::CreateCopyFromBuffer(const Windows::Storage::Streams::IBuffer & source, Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height)
{
    return get_activation_factory<SoftwareBitmap, ISoftwareBitmapStatics>().CreateCopyFromBuffer(source, format, width, height);
}

inline Windows::Graphics::Imaging::SoftwareBitmap SoftwareBitmap::CreateCopyFromBuffer(const Windows::Storage::Streams::IBuffer & source, Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha)
{
    return get_activation_factory<SoftwareBitmap, ISoftwareBitmapStatics>().CreateCopyFromBuffer(source, format, width, height, alpha);
}

inline Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> SoftwareBitmap::CreateCopyFromSurfaceAsync(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface)
{
    return get_activation_factory<SoftwareBitmap, ISoftwareBitmapStatics>().CreateCopyFromSurfaceAsync(surface);
}

inline Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> SoftwareBitmap::CreateCopyFromSurfaceAsync(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface, Windows::Graphics::Imaging::BitmapAlphaMode alpha)
{
    return get_activation_factory<SoftwareBitmap, ISoftwareBitmapStatics>().CreateCopyFromSurfaceAsync(surface, alpha);
}

}

}
#pragma warning(pop)
