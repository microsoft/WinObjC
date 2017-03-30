// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.DirectX.Direct3D11.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::Imaging {

struct BitmapBounds
{
    uint32_t X;
    uint32_t Y;
    uint32_t Width;
    uint32_t Height;
};

struct BitmapSize
{
    uint32_t Width;
    uint32_t Height;
};

struct BitmapPlaneDescription
{
    int32_t StartIndex;
    int32_t Width;
    int32_t Height;
    int32_t Stride;
};

}

namespace Windows::Graphics::Imaging {

using BitmapBounds = ABI::Windows::Graphics::Imaging::BitmapBounds;
using BitmapSize = ABI::Windows::Graphics::Imaging::BitmapSize;
using BitmapPlaneDescription = ABI::Windows::Graphics::Imaging::BitmapPlaneDescription;

}

namespace ABI::Windows::Graphics::Imaging {

struct __declspec(uuid("a53e04c4-399c-438c-b28f-a63a6b83d1a1")) __declspec(novtable) IBitmapBuffer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetPlaneCount(int32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetPlaneDescription(int32_t index, Windows::Graphics::Imaging::BitmapPlaneDescription * value) = 0;
};

struct __declspec(uuid("400caaf2-c4b0-4392-a3b0-6f6f9ba95cb4")) __declspec(novtable) IBitmapCodecInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CodecId(GUID * value) = 0;
    virtual HRESULT __stdcall get_FileExtensions(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_MimeTypes(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
};

struct __declspec(uuid("acef22ba-1d74-4c91-9dfc-9620745233e6")) __declspec(novtable) IBitmapDecoder : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BitmapContainerProperties(Windows::Graphics::Imaging::IBitmapPropertiesView ** value) = 0;
    virtual HRESULT __stdcall get_DecoderInformation(Windows::Graphics::Imaging::IBitmapCodecInformation ** value) = 0;
    virtual HRESULT __stdcall get_FrameCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetPreviewAsync(Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GetFrameAsync(uint32_t frameIndex, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapFrame> ** asyncInfo) = 0;
};

struct __declspec(uuid("438ccb26-bcef-4e95-bad6-23a822e58d01")) __declspec(novtable) IBitmapDecoderStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BmpDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_JpegDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_PngDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_TiffDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_GifDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_JpegXRDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_IcoDecoderId(GUID * value) = 0;
    virtual HRESULT __stdcall abi_GetDecoderInformationEnumerator(Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> ** decoderInformationEnumerator) = 0;
    virtual HRESULT __stdcall abi_CreateAsync(Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CreateWithIdAsync(GUID decoderId, Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> ** asyncInfo) = 0;
};

struct __declspec(uuid("2bc468e3-e1f8-4b54-95e8-32919551ce62")) __declspec(novtable) IBitmapEncoder : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EncoderInformation(Windows::Graphics::Imaging::IBitmapCodecInformation ** value) = 0;
    virtual HRESULT __stdcall get_BitmapProperties(Windows::Graphics::Imaging::IBitmapProperties ** value) = 0;
    virtual HRESULT __stdcall get_BitmapContainerProperties(Windows::Graphics::Imaging::IBitmapProperties ** value) = 0;
    virtual HRESULT __stdcall get_IsThumbnailGenerated(bool * value) = 0;
    virtual HRESULT __stdcall put_IsThumbnailGenerated(bool value) = 0;
    virtual HRESULT __stdcall get_GeneratedThumbnailWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_GeneratedThumbnailWidth(uint32_t value) = 0;
    virtual HRESULT __stdcall get_GeneratedThumbnailHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_GeneratedThumbnailHeight(uint32_t value) = 0;
    virtual HRESULT __stdcall get_BitmapTransform(Windows::Graphics::Imaging::IBitmapTransform ** value) = 0;
    virtual HRESULT __stdcall abi_SetPixelData(winrt::Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, uint32_t width, uint32_t height, double dpiX, double dpiY, uint32_t __pixelsSize, uint8_t * pixels) = 0;
    virtual HRESULT __stdcall abi_GoToNextFrameAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GoToNextFrameWithEncodingOptionsAsync(Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> * encodingOptions, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_FlushAsync(Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("a74356a7-a4e4-4eb9-8e40-564de7e1ccb2")) __declspec(novtable) IBitmapEncoderStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BmpEncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_JpegEncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_PngEncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_TiffEncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_GifEncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall get_JpegXREncoderId(GUID * value) = 0;
    virtual HRESULT __stdcall abi_GetEncoderInformationEnumerator(Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> ** encoderInformationEnumerator) = 0;
    virtual HRESULT __stdcall abi_CreateAsync(GUID encoderId, Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CreateWithEncodingOptionsAsync(GUID encoderId, Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> * encodingOptions, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CreateForTranscodingAsync(Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Graphics::Imaging::IBitmapDecoder * bitmapDecoder, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_CreateForInPlacePropertyEncodingAsync(Windows::Graphics::Imaging::IBitmapDecoder * bitmapDecoder, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> ** asyncInfo) = 0;
};

struct __declspec(uuid("686cd241-4330-4c77-ace4-0334968b1768")) __declspec(novtable) IBitmapEncoderWithSoftwareBitmap : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetSoftwareBitmap(Windows::Graphics::Imaging::ISoftwareBitmap * bitmap) = 0;
};

struct __declspec(uuid("72a49a1c-8081-438d-91bc-94ecfc8185c6")) __declspec(novtable) IBitmapFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetThumbnailAsync(Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> ** asyncInfo) = 0;
    virtual HRESULT __stdcall get_BitmapProperties(Windows::Graphics::Imaging::IBitmapPropertiesView ** value) = 0;
    virtual HRESULT __stdcall get_BitmapPixelFormat(winrt::Windows::Graphics::Imaging::BitmapPixelFormat * value) = 0;
    virtual HRESULT __stdcall get_BitmapAlphaMode(winrt::Windows::Graphics::Imaging::BitmapAlphaMode * value) = 0;
    virtual HRESULT __stdcall get_DpiX(double * value) = 0;
    virtual HRESULT __stdcall get_DpiY(double * value) = 0;
    virtual HRESULT __stdcall get_PixelWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_PixelHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_OrientedPixelWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_OrientedPixelHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetPixelDataAsync(Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_GetPixelDataTransformedAsync(winrt::Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, Windows::Graphics::Imaging::IBitmapTransform * transform, winrt::Windows::Graphics::Imaging::ExifOrientationMode exifOrientationMode, winrt::Windows::Graphics::Imaging::ColorManagementMode colorManagementMode, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider> ** asyncInfo) = 0;
};

struct __declspec(uuid("fe287c9a-420c-4963-87ad-691436e08383")) __declspec(novtable) IBitmapFrameWithSoftwareBitmap : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetSoftwareBitmapAsync(Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> ** value) = 0;
    virtual HRESULT __stdcall abi_GetSoftwareBitmapConvertedAsync(winrt::Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> ** value) = 0;
    virtual HRESULT __stdcall abi_GetSoftwareBitmapTransformedAsync(winrt::Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, Windows::Graphics::Imaging::IBitmapTransform * transform, winrt::Windows::Graphics::Imaging::ExifOrientationMode exifOrientationMode, winrt::Windows::Graphics::Imaging::ColorManagementMode colorManagementMode, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> ** value) = 0;
};

struct __declspec(uuid("ea9f4f1b-b505-4450-a4d1-e8ca94529d8d")) __declspec(novtable) IBitmapProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetPropertiesAsync(Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> * propertiesToSet, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("7e0fe87a-3a70-48f8-9c55-196cf5a545f5")) __declspec(novtable) IBitmapPropertiesView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetPropertiesAsync(Windows::Foundation::Collections::IIterable<hstring> * propertiesToRetrieve, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapPropertySet> ** asyncInfo) = 0;
};

struct __declspec(uuid("ae755344-e268-4d35-adcf-e995d31a8d34")) __declspec(novtable) IBitmapTransform : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ScaledWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ScaledWidth(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ScaledHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ScaledHeight(uint32_t value) = 0;
    virtual HRESULT __stdcall get_InterpolationMode(winrt::Windows::Graphics::Imaging::BitmapInterpolationMode * value) = 0;
    virtual HRESULT __stdcall put_InterpolationMode(winrt::Windows::Graphics::Imaging::BitmapInterpolationMode value) = 0;
    virtual HRESULT __stdcall get_Flip(winrt::Windows::Graphics::Imaging::BitmapFlip * value) = 0;
    virtual HRESULT __stdcall put_Flip(winrt::Windows::Graphics::Imaging::BitmapFlip value) = 0;
    virtual HRESULT __stdcall get_Rotation(winrt::Windows::Graphics::Imaging::BitmapRotation * value) = 0;
    virtual HRESULT __stdcall put_Rotation(winrt::Windows::Graphics::Imaging::BitmapRotation value) = 0;
    virtual HRESULT __stdcall get_Bounds(Windows::Graphics::Imaging::BitmapBounds * value) = 0;
    virtual HRESULT __stdcall put_Bounds(Windows::Graphics::Imaging::BitmapBounds value) = 0;
};

struct __declspec(uuid("cd8044a9-2443-4000-b0cd-79316c56f589")) __declspec(novtable) IBitmapTypedValue : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Value(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_Type(winrt::Windows::Foundation::PropertyType * value) = 0;
};

struct __declspec(uuid("92dbb599-ce13-46bb-9545-cb3a3f63eb8b")) __declspec(novtable) IBitmapTypedValueFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::IInspectable * value, winrt::Windows::Foundation::PropertyType type, Windows::Graphics::Imaging::IBitmapTypedValue ** bitmapTypedValue) = 0;
};

struct __declspec(uuid("dd831f25-185c-4595-9fb9-ccbe6ec18a6f")) __declspec(novtable) IPixelDataProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_DetachPixelData(uint32_t * __pixelDataSize, uint8_t ** pixelData) = 0;
};

struct __declspec(uuid("689e0708-7eef-483f-963f-da938818e073")) __declspec(novtable) ISoftwareBitmap : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BitmapPixelFormat(winrt::Windows::Graphics::Imaging::BitmapPixelFormat * value) = 0;
    virtual HRESULT __stdcall get_BitmapAlphaMode(winrt::Windows::Graphics::Imaging::BitmapAlphaMode * value) = 0;
    virtual HRESULT __stdcall get_PixelWidth(int32_t * value) = 0;
    virtual HRESULT __stdcall get_PixelHeight(int32_t * value) = 0;
    virtual HRESULT __stdcall get_IsReadOnly(bool * value) = 0;
    virtual HRESULT __stdcall put_DpiX(double value) = 0;
    virtual HRESULT __stdcall get_DpiX(double * value) = 0;
    virtual HRESULT __stdcall put_DpiY(double value) = 0;
    virtual HRESULT __stdcall get_DpiY(double * value) = 0;
    virtual HRESULT __stdcall abi_LockBuffer(winrt::Windows::Graphics::Imaging::BitmapBufferAccessMode mode, Windows::Graphics::Imaging::IBitmapBuffer ** value) = 0;
    virtual HRESULT __stdcall abi_CopyTo(Windows::Graphics::Imaging::ISoftwareBitmap * bitmap) = 0;
    virtual HRESULT __stdcall abi_CopyFromBuffer(Windows::Storage::Streams::IBuffer * buffer) = 0;
    virtual HRESULT __stdcall abi_CopyToBuffer(Windows::Storage::Streams::IBuffer * buffer) = 0;
    virtual HRESULT __stdcall abi_GetReadOnlyView(Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
};

struct __declspec(uuid("c99feb69-2d62-4d47-a6b3-4fdb6a07fdf8")) __declspec(novtable) ISoftwareBitmapFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithAlpha(winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alpha, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
};

struct __declspec(uuid("df0385db-672f-4a9d-806e-c2442f343e86")) __declspec(novtable) ISoftwareBitmapStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Copy(Windows::Graphics::Imaging::ISoftwareBitmap * source, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_Convert(Windows::Graphics::Imaging::ISoftwareBitmap * source, winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_ConvertWithAlpha(Windows::Graphics::Imaging::ISoftwareBitmap * source, winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alpha, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_CreateCopyFromBuffer(Windows::Storage::Streams::IBuffer * source, winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_CreateCopyWithAlphaFromBuffer(Windows::Storage::Streams::IBuffer * source, winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alpha, Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall abi_CreateCopyFromSurfaceAsync(Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface * surface, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> ** value) = 0;
    virtual HRESULT __stdcall abi_CreateCopyWithAlphaFromSurfaceAsync(Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface * surface, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alpha, Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Graphics::Imaging::BitmapBuffer> { using default_interface = Windows::Graphics::Imaging::IBitmapBuffer; };
template <> struct traits<Windows::Graphics::Imaging::BitmapCodecInformation> { using default_interface = Windows::Graphics::Imaging::IBitmapCodecInformation; };
template <> struct traits<Windows::Graphics::Imaging::BitmapDecoder> { using default_interface = Windows::Graphics::Imaging::IBitmapDecoder; };
template <> struct traits<Windows::Graphics::Imaging::BitmapEncoder> { using default_interface = Windows::Graphics::Imaging::IBitmapEncoder; };
template <> struct traits<Windows::Graphics::Imaging::BitmapFrame> { using default_interface = Windows::Graphics::Imaging::IBitmapFrame; };
template <> struct traits<Windows::Graphics::Imaging::BitmapProperties> { using default_interface = Windows::Graphics::Imaging::IBitmapProperties; };
template <> struct traits<Windows::Graphics::Imaging::BitmapPropertiesView> { using default_interface = Windows::Graphics::Imaging::IBitmapPropertiesView; };
template <> struct traits<Windows::Graphics::Imaging::BitmapPropertySet> { using default_interface = Windows::Foundation::Collections::IMap<hstring, Windows::Graphics::Imaging::BitmapTypedValue>; };
template <> struct traits<Windows::Graphics::Imaging::BitmapTransform> { using default_interface = Windows::Graphics::Imaging::IBitmapTransform; };
template <> struct traits<Windows::Graphics::Imaging::BitmapTypedValue> { using default_interface = Windows::Graphics::Imaging::IBitmapTypedValue; };
template <> struct traits<Windows::Graphics::Imaging::ImageStream> { using default_interface = Windows::Storage::Streams::IRandomAccessStreamWithContentType; };
template <> struct traits<Windows::Graphics::Imaging::PixelDataProvider> { using default_interface = Windows::Graphics::Imaging::IPixelDataProvider; };
template <> struct traits<Windows::Graphics::Imaging::SoftwareBitmap> { using default_interface = Windows::Graphics::Imaging::ISoftwareBitmap; };

}

namespace Windows::Graphics::Imaging {

template <typename D>
struct WINRT_EBO impl_IBitmapBuffer
{
    int32_t GetPlaneCount() const;
    Windows::Graphics::Imaging::BitmapPlaneDescription GetPlaneDescription(int32_t index) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapCodecInformation
{
    GUID CodecId() const;
    Windows::Foundation::Collections::IVectorView<hstring> FileExtensions() const;
    hstring FriendlyName() const;
    Windows::Foundation::Collections::IVectorView<hstring> MimeTypes() const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapDecoder
{
    Windows::Graphics::Imaging::BitmapPropertiesView BitmapContainerProperties() const;
    Windows::Graphics::Imaging::BitmapCodecInformation DecoderInformation() const;
    uint32_t FrameCount() const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> GetPreviewAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapFrame> GetFrameAsync(uint32_t frameIndex) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapDecoderStatics
{
    GUID BmpDecoderId() const;
    GUID JpegDecoderId() const;
    GUID PngDecoderId() const;
    GUID TiffDecoderId() const;
    GUID GifDecoderId() const;
    GUID JpegXRDecoderId() const;
    GUID IcoDecoderId() const;
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> GetDecoderInformationEnumerator() const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> CreateAsync(const Windows::Storage::Streams::IRandomAccessStream & stream) const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapDecoder> CreateAsync(GUID decoderId, const Windows::Storage::Streams::IRandomAccessStream & stream) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapEncoder
{
    Windows::Graphics::Imaging::BitmapCodecInformation EncoderInformation() const;
    Windows::Graphics::Imaging::BitmapProperties BitmapProperties() const;
    Windows::Graphics::Imaging::BitmapProperties BitmapContainerProperties() const;
    bool IsThumbnailGenerated() const;
    void IsThumbnailGenerated(bool value) const;
    uint32_t GeneratedThumbnailWidth() const;
    void GeneratedThumbnailWidth(uint32_t value) const;
    uint32_t GeneratedThumbnailHeight() const;
    void GeneratedThumbnailHeight(uint32_t value) const;
    Windows::Graphics::Imaging::BitmapTransform BitmapTransform() const;
    void SetPixelData(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, uint32_t width, uint32_t height, double dpiX, double dpiY, array_view<const uint8_t> pixels) const;
    Windows::Foundation::IAsyncAction GoToNextFrameAsync() const;
    Windows::Foundation::IAsyncAction GoToNextFrameAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> encodingOptions) const;
    Windows::Foundation::IAsyncAction FlushAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapEncoderStatics
{
    GUID BmpEncoderId() const;
    GUID JpegEncoderId() const;
    GUID PngEncoderId() const;
    GUID TiffEncoderId() const;
    GUID GifEncoderId() const;
    GUID JpegXREncoderId() const;
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::Imaging::BitmapCodecInformation> GetEncoderInformationEnumerator() const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> CreateAsync(GUID encoderId, const Windows::Storage::Streams::IRandomAccessStream & stream) const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> CreateAsync(GUID encoderId, const Windows::Storage::Streams::IRandomAccessStream & stream, iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> encodingOptions) const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> CreateForTranscodingAsync(const Windows::Storage::Streams::IRandomAccessStream & stream, const Windows::Graphics::Imaging::BitmapDecoder & bitmapDecoder) const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapEncoder> CreateForInPlacePropertyEncodingAsync(const Windows::Graphics::Imaging::BitmapDecoder & bitmapDecoder) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapEncoderWithSoftwareBitmap
{
    void SetSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & bitmap) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapFrame
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::ImageStream> GetThumbnailAsync() const;
    Windows::Graphics::Imaging::BitmapPropertiesView BitmapProperties() const;
    Windows::Graphics::Imaging::BitmapPixelFormat BitmapPixelFormat() const;
    Windows::Graphics::Imaging::BitmapAlphaMode BitmapAlphaMode() const;
    double DpiX() const;
    double DpiY() const;
    uint32_t PixelWidth() const;
    uint32_t PixelHeight() const;
    uint32_t OrientedPixelWidth() const;
    uint32_t OrientedPixelHeight() const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider> GetPixelDataAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::PixelDataProvider> GetPixelDataAsync(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, const Windows::Graphics::Imaging::BitmapTransform & transform, Windows::Graphics::Imaging::ExifOrientationMode exifOrientationMode, Windows::Graphics::Imaging::ColorManagementMode colorManagementMode) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapFrameWithSoftwareBitmap
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> GetSoftwareBitmapAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> GetSoftwareBitmapAsync(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode) const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> GetSoftwareBitmapAsync(Windows::Graphics::Imaging::BitmapPixelFormat pixelFormat, Windows::Graphics::Imaging::BitmapAlphaMode alphaMode, const Windows::Graphics::Imaging::BitmapTransform & transform, Windows::Graphics::Imaging::ExifOrientationMode exifOrientationMode, Windows::Graphics::Imaging::ColorManagementMode colorManagementMode) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapProperties
{
    Windows::Foundation::IAsyncAction SetPropertiesAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Graphics::Imaging::BitmapTypedValue>> propertiesToSet) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapPropertiesView
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::BitmapPropertySet> GetPropertiesAsync(iterable<hstring> propertiesToRetrieve) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapTransform
{
    uint32_t ScaledWidth() const;
    void ScaledWidth(uint32_t value) const;
    uint32_t ScaledHeight() const;
    void ScaledHeight(uint32_t value) const;
    Windows::Graphics::Imaging::BitmapInterpolationMode InterpolationMode() const;
    void InterpolationMode(Windows::Graphics::Imaging::BitmapInterpolationMode value) const;
    Windows::Graphics::Imaging::BitmapFlip Flip() const;
    void Flip(Windows::Graphics::Imaging::BitmapFlip value) const;
    Windows::Graphics::Imaging::BitmapRotation Rotation() const;
    void Rotation(Windows::Graphics::Imaging::BitmapRotation value) const;
    Windows::Graphics::Imaging::BitmapBounds Bounds() const;
    void Bounds(const Windows::Graphics::Imaging::BitmapBounds & value) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapTypedValue
{
    Windows::Foundation::IInspectable Value() const;
    Windows::Foundation::PropertyType Type() const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapTypedValueFactory
{
    Windows::Graphics::Imaging::BitmapTypedValue Create(const Windows::Foundation::IInspectable & value, Windows::Foundation::PropertyType type) const;
};

template <typename D>
struct WINRT_EBO impl_IPixelDataProvider
{
    com_array<uint8_t> DetachPixelData() const;
};

template <typename D>
struct WINRT_EBO impl_ISoftwareBitmap
{
    Windows::Graphics::Imaging::BitmapPixelFormat BitmapPixelFormat() const;
    Windows::Graphics::Imaging::BitmapAlphaMode BitmapAlphaMode() const;
    int32_t PixelWidth() const;
    int32_t PixelHeight() const;
    bool IsReadOnly() const;
    void DpiX(double value) const;
    double DpiX() const;
    void DpiY(double value) const;
    double DpiY() const;
    Windows::Graphics::Imaging::BitmapBuffer LockBuffer(Windows::Graphics::Imaging::BitmapBufferAccessMode mode) const;
    void CopyTo(const Windows::Graphics::Imaging::SoftwareBitmap & bitmap) const;
    void CopyFromBuffer(const Windows::Storage::Streams::IBuffer & buffer) const;
    void CopyToBuffer(const Windows::Storage::Streams::IBuffer & buffer) const;
    Windows::Graphics::Imaging::SoftwareBitmap GetReadOnlyView() const;
};

template <typename D>
struct WINRT_EBO impl_ISoftwareBitmapFactory
{
    Windows::Graphics::Imaging::SoftwareBitmap Create(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height) const;
    Windows::Graphics::Imaging::SoftwareBitmap CreateWithAlpha(Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const;
};

template <typename D>
struct WINRT_EBO impl_ISoftwareBitmapStatics
{
    Windows::Graphics::Imaging::SoftwareBitmap Copy(const Windows::Graphics::Imaging::SoftwareBitmap & source) const;
    Windows::Graphics::Imaging::SoftwareBitmap Convert(const Windows::Graphics::Imaging::SoftwareBitmap & source, Windows::Graphics::Imaging::BitmapPixelFormat format) const;
    Windows::Graphics::Imaging::SoftwareBitmap Convert(const Windows::Graphics::Imaging::SoftwareBitmap & source, Windows::Graphics::Imaging::BitmapPixelFormat format, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const;
    Windows::Graphics::Imaging::SoftwareBitmap CreateCopyFromBuffer(const Windows::Storage::Streams::IBuffer & source, Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height) const;
    Windows::Graphics::Imaging::SoftwareBitmap CreateCopyFromBuffer(const Windows::Storage::Streams::IBuffer & source, Windows::Graphics::Imaging::BitmapPixelFormat format, int32_t width, int32_t height, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> CreateCopyFromSurfaceAsync(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface) const;
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Imaging::SoftwareBitmap> CreateCopyFromSurfaceAsync(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surface, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const;
};

}

namespace impl {

template <> struct traits<Windows::Graphics::Imaging::IBitmapBuffer>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapBuffer;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapBuffer<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapCodecInformation>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapCodecInformation;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapCodecInformation<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapDecoder>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapDecoder;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapDecoder<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapDecoderStatics>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapDecoderStatics;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapDecoderStatics<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapEncoder>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapEncoder;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapEncoder<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapEncoderStatics>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapEncoderStatics;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapEncoderStatics<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapEncoderWithSoftwareBitmap<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapFrame>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapFrame;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapFrame<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapFrameWithSoftwareBitmap<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapProperties>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapProperties;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapProperties<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapPropertiesView>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapPropertiesView;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapPropertiesView<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapTransform>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapTransform;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapTransform<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapTypedValue>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapTypedValue;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapTypedValue<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IBitmapTypedValueFactory>
{
    using abi = ABI::Windows::Graphics::Imaging::IBitmapTypedValueFactory;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IBitmapTypedValueFactory<D>;
};

template <> struct traits<Windows::Graphics::Imaging::IPixelDataProvider>
{
    using abi = ABI::Windows::Graphics::Imaging::IPixelDataProvider;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_IPixelDataProvider<D>;
};

template <> struct traits<Windows::Graphics::Imaging::ISoftwareBitmap>
{
    using abi = ABI::Windows::Graphics::Imaging::ISoftwareBitmap;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_ISoftwareBitmap<D>;
};

template <> struct traits<Windows::Graphics::Imaging::ISoftwareBitmapFactory>
{
    using abi = ABI::Windows::Graphics::Imaging::ISoftwareBitmapFactory;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_ISoftwareBitmapFactory<D>;
};

template <> struct traits<Windows::Graphics::Imaging::ISoftwareBitmapStatics>
{
    using abi = ABI::Windows::Graphics::Imaging::ISoftwareBitmapStatics;
    template <typename D> using consume = Windows::Graphics::Imaging::impl_ISoftwareBitmapStatics<D>;
};

template <> struct traits<Windows::Graphics::Imaging::BitmapBuffer>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapBuffer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapBuffer"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapCodecInformation>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapCodecInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapCodecInformation"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapDecoder>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapDecoder;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapDecoder"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapEncoder>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapEncoder;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapEncoder"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapFrame>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapFrame"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapProperties>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapProperties"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapPropertiesView>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapPropertiesView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapPropertiesView"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapPropertySet>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapPropertySet;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapPropertySet"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapTransform>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapTransform;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapTransform"; }
};

template <> struct traits<Windows::Graphics::Imaging::BitmapTypedValue>
{
    using abi = ABI::Windows::Graphics::Imaging::BitmapTypedValue;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.BitmapTypedValue"; }
};

template <> struct traits<Windows::Graphics::Imaging::ImageStream>
{
    using abi = ABI::Windows::Graphics::Imaging::ImageStream;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.ImageStream"; }
};

template <> struct traits<Windows::Graphics::Imaging::PixelDataProvider>
{
    using abi = ABI::Windows::Graphics::Imaging::PixelDataProvider;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.PixelDataProvider"; }
};

template <> struct traits<Windows::Graphics::Imaging::SoftwareBitmap>
{
    using abi = ABI::Windows::Graphics::Imaging::SoftwareBitmap;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Imaging.SoftwareBitmap"; }
};

}

}
