// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.FaceAnalysis.0.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.Media.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Graphics.Imaging.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::FaceAnalysis {

struct __declspec(uuid("8200d454-66bc-34df-9410-e89400195414")) __declspec(novtable) IDetectedFace : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FaceBox(Windows::Graphics::Imaging::BitmapBounds * returnValue) = 0;
};

struct __declspec(uuid("16b672dc-fe6f-3117-8d95-c3f04d51630c")) __declspec(novtable) IFaceDetector : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_DetectFacesAsync(Windows::Graphics::Imaging::ISoftwareBitmap * image, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_DetectFacesWithSearchAreaAsync(Windows::Graphics::Imaging::ISoftwareBitmap * image, Windows::Graphics::Imaging::BitmapBounds searchArea, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> ** returnValue) = 0;
    virtual HRESULT __stdcall get_MinDetectableFaceSize(Windows::Graphics::Imaging::BitmapSize * returnValue) = 0;
    virtual HRESULT __stdcall put_MinDetectableFaceSize(Windows::Graphics::Imaging::BitmapSize value) = 0;
    virtual HRESULT __stdcall get_MaxDetectableFaceSize(Windows::Graphics::Imaging::BitmapSize * returnValue) = 0;
    virtual HRESULT __stdcall put_MaxDetectableFaceSize(Windows::Graphics::Imaging::BitmapSize value) = 0;
};

struct __declspec(uuid("bc042d67-9047-33f6-881b-6746c1b218b8")) __declspec(novtable) IFaceDetectorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateAsync(Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetSupportedBitmapPixelFormats(Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> ** result) = 0;
    virtual HRESULT __stdcall abi_IsBitmapPixelFormatSupported(winrt::Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat, bool * result) = 0;
    virtual HRESULT __stdcall get_IsSupported(bool * returnValue) = 0;
};

struct __declspec(uuid("6ba67d8c-a841-4420-93e6-2420a1884fcf")) __declspec(novtable) IFaceTracker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ProcessNextFrameAsync(Windows::Media::IVideoFrame * videoFrame, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> ** returnValue) = 0;
    virtual HRESULT __stdcall get_MinDetectableFaceSize(Windows::Graphics::Imaging::BitmapSize * returnValue) = 0;
    virtual HRESULT __stdcall put_MinDetectableFaceSize(Windows::Graphics::Imaging::BitmapSize value) = 0;
    virtual HRESULT __stdcall get_MaxDetectableFaceSize(Windows::Graphics::Imaging::BitmapSize * returnValue) = 0;
    virtual HRESULT __stdcall put_MaxDetectableFaceSize(Windows::Graphics::Imaging::BitmapSize value) = 0;
};

struct __declspec(uuid("e9629198-1801-3fa5-932e-31d767af6c4d")) __declspec(novtable) IFaceTrackerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateAsync(Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetSupportedBitmapPixelFormats(Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> ** result) = 0;
    virtual HRESULT __stdcall abi_IsBitmapPixelFormatSupported(winrt::Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat, bool * result) = 0;
    virtual HRESULT __stdcall get_IsSupported(bool * returnValue) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::FaceAnalysis::DetectedFace> { using default_interface = Windows::Media::FaceAnalysis::IDetectedFace; };
template <> struct traits<Windows::Media::FaceAnalysis::FaceDetector> { using default_interface = Windows::Media::FaceAnalysis::IFaceDetector; };
template <> struct traits<Windows::Media::FaceAnalysis::FaceTracker> { using default_interface = Windows::Media::FaceAnalysis::IFaceTracker; };

}

namespace Windows::Media::FaceAnalysis {

template <typename D>
struct WINRT_EBO impl_IDetectedFace
{
    Windows::Graphics::Imaging::BitmapBounds FaceBox() const;
};

template <typename D>
struct WINRT_EBO impl_IFaceDetector
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> DetectFacesAsync(const Windows::Graphics::Imaging::SoftwareBitmap & image) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> DetectFacesAsync(const Windows::Graphics::Imaging::SoftwareBitmap & image, const Windows::Graphics::Imaging::BitmapBounds & searchArea) const;
    Windows::Graphics::Imaging::BitmapSize MinDetectableFaceSize() const;
    void MinDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const;
    Windows::Graphics::Imaging::BitmapSize MaxDetectableFaceSize() const;
    void MaxDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const;
};

template <typename D>
struct WINRT_EBO impl_IFaceDetectorStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector> CreateAsync() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> GetSupportedBitmapPixelFormats() const;
    bool IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat) const;
    bool IsSupported() const;
};

template <typename D>
struct WINRT_EBO impl_IFaceTracker
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> ProcessNextFrameAsync(const Windows::Media::VideoFrame & videoFrame) const;
    Windows::Graphics::Imaging::BitmapSize MinDetectableFaceSize() const;
    void MinDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const;
    Windows::Graphics::Imaging::BitmapSize MaxDetectableFaceSize() const;
    void MaxDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const;
};

template <typename D>
struct WINRT_EBO impl_IFaceTrackerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker> CreateAsync() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> GetSupportedBitmapPixelFormats() const;
    bool IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat) const;
    bool IsSupported() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::FaceAnalysis::IDetectedFace>
{
    using abi = ABI::Windows::Media::FaceAnalysis::IDetectedFace;
    template <typename D> using consume = Windows::Media::FaceAnalysis::impl_IDetectedFace<D>;
};

template <> struct traits<Windows::Media::FaceAnalysis::IFaceDetector>
{
    using abi = ABI::Windows::Media::FaceAnalysis::IFaceDetector;
    template <typename D> using consume = Windows::Media::FaceAnalysis::impl_IFaceDetector<D>;
};

template <> struct traits<Windows::Media::FaceAnalysis::IFaceDetectorStatics>
{
    using abi = ABI::Windows::Media::FaceAnalysis::IFaceDetectorStatics;
    template <typename D> using consume = Windows::Media::FaceAnalysis::impl_IFaceDetectorStatics<D>;
};

template <> struct traits<Windows::Media::FaceAnalysis::IFaceTracker>
{
    using abi = ABI::Windows::Media::FaceAnalysis::IFaceTracker;
    template <typename D> using consume = Windows::Media::FaceAnalysis::impl_IFaceTracker<D>;
};

template <> struct traits<Windows::Media::FaceAnalysis::IFaceTrackerStatics>
{
    using abi = ABI::Windows::Media::FaceAnalysis::IFaceTrackerStatics;
    template <typename D> using consume = Windows::Media::FaceAnalysis::impl_IFaceTrackerStatics<D>;
};

template <> struct traits<Windows::Media::FaceAnalysis::DetectedFace>
{
    using abi = ABI::Windows::Media::FaceAnalysis::DetectedFace;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.FaceAnalysis.DetectedFace"; }
};

template <> struct traits<Windows::Media::FaceAnalysis::FaceDetector>
{
    using abi = ABI::Windows::Media::FaceAnalysis::FaceDetector;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.FaceAnalysis.FaceDetector"; }
};

template <> struct traits<Windows::Media::FaceAnalysis::FaceTracker>
{
    using abi = ABI::Windows::Media::FaceAnalysis::FaceTracker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.FaceAnalysis.FaceTracker"; }
};

}

}
