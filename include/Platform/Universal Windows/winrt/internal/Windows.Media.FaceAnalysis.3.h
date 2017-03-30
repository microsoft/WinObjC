// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.FaceAnalysis.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::FaceAnalysis {

struct WINRT_EBO DetectedFace :
    Windows::Media::FaceAnalysis::IDetectedFace
{
    DetectedFace(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FaceDetector :
    Windows::Media::FaceAnalysis::IFaceDetector
{
    FaceDetector(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceDetector> CreateAsync();
    static Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> GetSupportedBitmapPixelFormats();
    static bool IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat);
    static bool IsSupported();
};

struct WINRT_EBO FaceTracker :
    Windows::Media::FaceAnalysis::IFaceTracker
{
    FaceTracker(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Media::FaceAnalysis::FaceTracker> CreateAsync();
    static Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::Imaging::BitmapPixelFormat> GetSupportedBitmapPixelFormats();
    static bool IsBitmapPixelFormatSupported(Windows::Graphics::Imaging::BitmapPixelFormat bitmapPixelFormat);
    static bool IsSupported();
};

}

}
