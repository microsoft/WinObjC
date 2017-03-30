// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Imaging.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::Imaging {

struct WINRT_EBO BitmapBuffer :
    Windows::Graphics::Imaging::IBitmapBuffer
{
    BitmapBuffer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BitmapCodecInformation :
    Windows::Graphics::Imaging::IBitmapCodecInformation
{
    BitmapCodecInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BitmapDecoder :
    Windows::Graphics::Imaging::IBitmapDecoder,
    impl::require<BitmapDecoder, Windows::Graphics::Imaging::IBitmapFrame, Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>
{
    BitmapDecoder(std::nullptr_t) noexcept {}
    static GUID BmpDecoderId();
    static GUID JpegDecoderId();
    static GUID PngDecoderId();
    static GUID TiffDecoderId();
    static GUID GifDecoderId();
    static GUID JpegXRDecoderId();
    static GUID IcoDecoderId();
    static Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> GetDecoderInformationEnumerator();
    static Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> CreateAsync(const Windows::Storage::Streams::IRandomAccessStream & stream);
    static Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> CreateAsync(GUID decoderId, const Windows::Storage::Streams::IRandomAccessStream & stream);
};

struct WINRT_EBO BitmapEncoder :
    Windows::Graphics::Imaging::IBitmapEncoder,
    impl::require<BitmapEncoder, Windows::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap>
{
    BitmapEncoder(std::nullptr_t) noexcept {}
    static GUID BmpEncoderId();
    static GUID JpegEncoderId();
    static GUID PngEncoderId();
    static GUID TiffEncoderId();
    static GUID GifEncoderId();
    static GUID JpegXREncoderId();
    static Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> GetEncoderInformationEnumerator();
    static Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> CreateAsync(GUID encoderId, const Windows::Storage::Streams::IRandomAccessStream & stream);
    static Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> CreateAsync(GUID encoderId, const Windows::Storage::Streams::IRandomAccessStream & stream, iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> encodingOptions);
    static Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> CreateForTranscodingAsync(const Windows::Storage::Streams::IRandomAccessStream & stream, const Windows::Graphics::Imaging::BitmapDecoder & bitmapDecoder);
    static Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> CreateForInPlacePropertyEncodingAsync(const Windows::Graphics::Imaging::BitmapDecoder & bitmapDecoder);
};

struct WINRT_EBO BitmapFrame :
    Windows::Graphics::Imaging::IBitmapFrame,
    impl::require<BitmapFrame, Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>
{
    BitmapFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BitmapProperties :
    Windows::Graphics::Imaging::IBitmapProperties
{
    BitmapProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BitmapPropertiesView :
    Windows::Graphics::Imaging::IBitmapPropertiesView
{
    BitmapPropertiesView(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BitmapPropertySet :
    Windows::Foundation::Collections::IMap<hstring, Windows::Graphics::Imaging::BitmapTypedValue>
{
    BitmapPropertySet(std::nullptr_t) noexcept {}
    BitmapPropertySet();
};

struct WINRT_EBO BitmapTransform :
    Windows::Graphics::Imaging::IBitmapTransform
{
    BitmapTransform(std::nullptr_t) noexcept {}
    BitmapTransform();
};

struct WINRT_EBO BitmapTypedValue :
    Windows::Graphics::Imaging::IBitmapTypedValue
{
    BitmapTypedValue(std::nullptr_t) noexcept {}
    BitmapTypedValue(const Windows::Foundation::IInspectable & value, Windows::Foundation::PropertyType type);
};

struct WINRT_EBO ImageStream :
    Windows::Storage::Streams::IRandomAccessStreamWithContentType
{
    ImageStream(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PixelDataProvider :
    Windows::Graphics::Imaging::IPixelDataProvider
{
    PixelDataProvider(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SoftwareBitmap :
    Windows::Graphics::Imaging::ISoftwareBitmap
{
    SoftwareBitmap(std::nullptr_t) noexcept {}
    SoftwareBitmap(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height);
    SoftwareBitmap(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha);
    static Windows::Graphics::Imaging::SoftwareBitmap Copy(const Windows::Graphics::Imaging::SoftwareBitmap & source);
    static Windows::Graphics::Imaging::SoftwareBitmap Convert(const Windows::Graphics::Imaging::SoftwareBitmap & source, Windows::Graphics::Imaging::BitmapPixelFormat format);
    static Windows::Graphics::Imaging::SoftwareBitmap Convert(const Windows::Graphics::Imaging::SoftwareBitmap & source, Windows::Graphics::Imaging::BitmapPixelFormat format, Windows::Graphics::Imaging::BitmapAlphaMode alpha);
    static Windows::Graphics::Imaging::SoftwareBitmap CreateCopyFromBuffer(const Windows::Storage::Streams::IBuffer & source, Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height);
    static Windows::Graphics::Imaging::SoftwareBitmap CreateCopyFromBuffer(const Windows::Storage::Streams::IBuffer & source, Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha);
    static Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> CreateCopyFromSurfaceAsync(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface);
    static Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> CreateCopyFromSurfaceAsync(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface, Windows::Graphics::Imaging::BitmapAlphaMode alpha);
};

}

}
