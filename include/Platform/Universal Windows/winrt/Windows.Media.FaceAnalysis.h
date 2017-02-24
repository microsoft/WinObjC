// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.3.h"
#include "internal/Windows.Media.FaceAnalysis.3.h"
#include "Windows.Media.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::FaceAnalysis::IDetectedFace> : produce_base<D, Windows::Media::FaceAnalysis::IDetectedFace>
{
    HRESULT __stdcall get_FaceBox(impl::abi_arg_out<Windows::Graphics::Imaging::BitmapBounds> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FaceBox());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::FaceAnalysis::IFaceDetector> : produce_base<D, Windows::Media::FaceAnalysis::IFaceDetector>
{
    HRESULT __stdcall abi_DetectFacesAsync(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> image, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().DetectFacesAsync(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&image)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DetectFacesWithSearchAreaAsync(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> image, impl::abi_arg_in<Windows::Graphics::Imaging::BitmapBounds> searchArea, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().DetectFacesAsync(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&image), *reinterpret_cast<const Windows::Graphics::Imaging::BitmapBounds *>(&searchArea)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinDetectableFaceSize(impl::abi_arg_out<Windows::Graphics::Imaging::BitmapSize> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MinDetectableFaceSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinDetectableFaceSize(impl::abi_arg_in<Windows::Graphics::Imaging::BitmapSize> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinDetectableFaceSize(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxDetectableFaceSize(impl::abi_arg_out<Windows::Graphics::Imaging::BitmapSize> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MaxDetectableFaceSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxDetectableFaceSize(impl::abi_arg_in<Windows::Graphics::Imaging::BitmapSize> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxDetectableFaceSize(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::FaceAnalysis::IFaceDetectorStatics> : produce_base<D, Windows::Media::FaceAnalysis::IFaceDetectorStatics>
{
    HRESULT __stdcall abi_CreateAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSupportedBitmapPixelFormats(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSupportedBitmapPixelFormats());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsBitmapPixelFormatSupported(bitmapPixelFormat));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSupported(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::FaceAnalysis::IFaceTracker> : produce_base<D, Windows::Media::FaceAnalysis::IFaceTracker>
{
    HRESULT __stdcall abi_ProcessNextFrameAsync(impl::abi_arg_in<Windows::Media::IVideoFrame> videoFrame, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ProcessNextFrameAsync(*reinterpret_cast<const Windows::Media::VideoFrame *>(&videoFrame)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinDetectableFaceSize(impl::abi_arg_out<Windows::Graphics::Imaging::BitmapSize> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MinDetectableFaceSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinDetectableFaceSize(impl::abi_arg_in<Windows::Graphics::Imaging::BitmapSize> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinDetectableFaceSize(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxDetectableFaceSize(impl::abi_arg_out<Windows::Graphics::Imaging::BitmapSize> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MaxDetectableFaceSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxDetectableFaceSize(impl::abi_arg_in<Windows::Graphics::Imaging::BitmapSize> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxDetectableFaceSize(*reinterpret_cast<const Windows::Graphics::Imaging::BitmapSize *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::FaceAnalysis::IFaceTrackerStatics> : produce_base<D, Windows::Media::FaceAnalysis::IFaceTrackerStatics>
{
    HRESULT __stdcall abi_CreateAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSupportedBitmapPixelFormats(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSupportedBitmapPixelFormats());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsBitmapPixelFormatSupported(bitmapPixelFormat));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSupported(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::FaceAnalysis {

template <typename D> Windows::Graphics::Imaging::BitmapBounds impl_IDetectedFace<D>::FaceBox() const
{
    Windows::Graphics::Imaging::BitmapBounds returnValue {};
    check_hresult(WINRT_SHIM(IDetectedFace)->get_FaceBox(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> impl_IFaceDetector<D>::DetectFacesAsync(const Windows::Graphics::Imaging::SoftwareBitmap & image) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> returnValue;
    check_hresult(WINRT_SHIM(IFaceDetector)->abi_DetectFacesAsync(get_abi(image), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> impl_IFaceDetector<D>::DetectFacesAsync(const Windows::Graphics::Imaging::SoftwareBitmap & image, const Windows::Graphics::Imaging::BitmapBounds & searchArea) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> returnValue;
    check_hresult(WINRT_SHIM(IFaceDetector)->abi_DetectFacesWithSearchAreaAsync(get_abi(image), get_abi(searchArea), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Graphics::Imaging::BitmapSize impl_IFaceDetector<D>::MinDetectableFaceSize() const
{
    Windows::Graphics::Imaging::BitmapSize returnValue {};
    check_hresult(WINRT_SHIM(IFaceDetector)->get_MinDetectableFaceSize(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IFaceDetector<D>::MinDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const
{
    check_hresult(WINRT_SHIM(IFaceDetector)->put_MinDetectableFaceSize(get_abi(value)));
}

template <typename D> Windows::Graphics::Imaging::BitmapSize impl_IFaceDetector<D>::MaxDetectableFaceSize() const
{
    Windows::Graphics::Imaging::BitmapSize returnValue {};
    check_hresult(WINRT_SHIM(IFaceDetector)->get_MaxDetectableFaceSize(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IFaceDetector<D>::MaxDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const
{
    check_hresult(WINRT_SHIM(IFaceDetector)->put_MaxDetectableFaceSize(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector> impl_IFaceDetectorStatics<D>::CreateAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector> returnValue;
    check_hresult(WINRT_SHIM(IFaceDetectorStatics)->abi_CreateAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> impl_IFaceDetectorStatics<D>::GetSupportedBitmapPixelFormats() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> result;
    check_hresult(WINRT_SHIM(IFaceDetectorStatics)->abi_GetSupportedBitmapPixelFormats(put_abi(result)));
    return result;
}

template <typename D> bool impl_IFaceDetectorStatics<D>::IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IFaceDetectorStatics)->abi_IsBitmapPixelFormatSupported(bitmapPixelFormat, &result));
    return result;
}

template <typename D> bool impl_IFaceDetectorStatics<D>::IsSupported() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IFaceDetectorStatics)->get_IsSupported(&returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> impl_IFaceTracker<D>::ProcessNextFrameAsync(const Windows::Media::VideoFrame & videoFrame) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<Windows::Media::FaceAnalysis::DetectedFace>> returnValue;
    check_hresult(WINRT_SHIM(IFaceTracker)->abi_ProcessNextFrameAsync(get_abi(videoFrame), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Graphics::Imaging::BitmapSize impl_IFaceTracker<D>::MinDetectableFaceSize() const
{
    Windows::Graphics::Imaging::BitmapSize returnValue {};
    check_hresult(WINRT_SHIM(IFaceTracker)->get_MinDetectableFaceSize(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IFaceTracker<D>::MinDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const
{
    check_hresult(WINRT_SHIM(IFaceTracker)->put_MinDetectableFaceSize(get_abi(value)));
}

template <typename D> Windows::Graphics::Imaging::BitmapSize impl_IFaceTracker<D>::MaxDetectableFaceSize() const
{
    Windows::Graphics::Imaging::BitmapSize returnValue {};
    check_hresult(WINRT_SHIM(IFaceTracker)->get_MaxDetectableFaceSize(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IFaceTracker<D>::MaxDetectableFaceSize(const Windows::Graphics::Imaging::BitmapSize & value) const
{
    check_hresult(WINRT_SHIM(IFaceTracker)->put_MaxDetectableFaceSize(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker> impl_IFaceTrackerStatics<D>::CreateAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker> returnValue;
    check_hresult(WINRT_SHIM(IFaceTrackerStatics)->abi_CreateAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> impl_IFaceTrackerStatics<D>::GetSupportedBitmapPixelFormats() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> result;
    check_hresult(WINRT_SHIM(IFaceTrackerStatics)->abi_GetSupportedBitmapPixelFormats(put_abi(result)));
    return result;
}

template <typename D> bool impl_IFaceTrackerStatics<D>::IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IFaceTrackerStatics)->abi_IsBitmapPixelFormatSupported(bitmapPixelFormat, &result));
    return result;
}

template <typename D> bool impl_IFaceTrackerStatics<D>::IsSupported() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IFaceTrackerStatics)->get_IsSupported(&returnValue));
    return returnValue;
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector> FaceDetector::CreateAsync()
{
    return get_activation_factory<FaceDetector, IFaceDetectorStatics>().CreateAsync();
}

inline Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> FaceDetector::GetSupportedBitmapPixelFormats()
{
    return get_activation_factory<FaceDetector, IFaceDetectorStatics>().GetSupportedBitmapPixelFormats();
}

inline bool FaceDetector::IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat)
{
    return get_activation_factory<FaceDetector, IFaceDetectorStatics>().IsBitmapPixelFormatSupported(bitmapPixelFormat);
}

inline bool FaceDetector::IsSupported()
{
    return get_activation_factory<FaceDetector, IFaceDetectorStatics>().IsSupported();
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker> FaceTracker::CreateAsync()
{
    return get_activation_factory<FaceTracker, IFaceTrackerStatics>().CreateAsync();
}

inline Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> FaceTracker::GetSupportedBitmapPixelFormats()
{
    return get_activation_factory<FaceTracker, IFaceTrackerStatics>().GetSupportedBitmapPixelFormats();
}

inline bool FaceTracker::IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat)
{
    return get_activation_factory<FaceTracker, IFaceTrackerStatics>().IsBitmapPixelFormatSupported(bitmapPixelFormat);
}

inline bool FaceTracker::IsSupported()
{
    return get_activation_factory<FaceTracker, IFaceTrackerStatics>().IsSupported();
}

}

}
#pragma warning(pop)
