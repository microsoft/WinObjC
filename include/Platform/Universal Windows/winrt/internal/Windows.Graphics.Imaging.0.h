// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::Imaging {

struct BitmapBounds;
struct BitmapSize;
struct BitmapPlaneDescription;

}

namespace Windows::Graphics::Imaging {

using BitmapBounds = ABI::Windows::Graphics::Imaging::BitmapBounds;
using BitmapSize = ABI::Windows::Graphics::Imaging::BitmapSize;
using BitmapPlaneDescription = ABI::Windows::Graphics::Imaging::BitmapPlaneDescription;

}

namespace ABI::Windows::Graphics::Imaging {

struct IBitmapBuffer;
struct IBitmapCodecInformation;
struct IBitmapDecoder;
struct IBitmapDecoderStatics;
struct IBitmapEncoder;
struct IBitmapEncoderStatics;
struct IBitmapEncoderWithSoftwareBitmap;
struct IBitmapFrame;
struct IBitmapFrameWithSoftwareBitmap;
struct IBitmapProperties;
struct IBitmapPropertiesView;
struct IBitmapTransform;
struct IBitmapTypedValue;
struct IBitmapTypedValueFactory;
struct IPixelDataProvider;
struct ISoftwareBitmap;
struct ISoftwareBitmapFactory;
struct ISoftwareBitmapStatics;
struct BitmapBuffer;
struct BitmapCodecInformation;
struct BitmapDecoder;
struct BitmapEncoder;
struct BitmapFrame;
struct BitmapProperties;
struct BitmapPropertiesView;
struct BitmapPropertySet;
struct BitmapTransform;
struct BitmapTypedValue;
struct ImageStream;
struct PixelDataProvider;
struct SoftwareBitmap;

}

namespace Windows::Graphics::Imaging {

struct IBitmapBuffer;
struct IBitmapCodecInformation;
struct IBitmapDecoder;
struct IBitmapDecoderStatics;
struct IBitmapEncoder;
struct IBitmapEncoderStatics;
struct IBitmapEncoderWithSoftwareBitmap;
struct IBitmapFrame;
struct IBitmapFrameWithSoftwareBitmap;
struct IBitmapProperties;
struct IBitmapPropertiesView;
struct IBitmapTransform;
struct IBitmapTypedValue;
struct IBitmapTypedValueFactory;
struct IPixelDataProvider;
struct ISoftwareBitmap;
struct ISoftwareBitmapFactory;
struct ISoftwareBitmapStatics;
struct BitmapBuffer;
struct BitmapCodecInformation;
struct BitmapDecoder;
struct BitmapEncoder;
struct BitmapFrame;
struct BitmapProperties;
struct BitmapPropertiesView;
struct BitmapPropertySet;
struct BitmapTransform;
struct BitmapTypedValue;
struct ImageStream;
struct PixelDataProvider;
struct SoftwareBitmap;

}

namespace Windows::Graphics::Imaging {

template <typename T> struct impl_IBitmapBuffer;
template <typename T> struct impl_IBitmapCodecInformation;
template <typename T> struct impl_IBitmapDecoder;
template <typename T> struct impl_IBitmapDecoderStatics;
template <typename T> struct impl_IBitmapEncoder;
template <typename T> struct impl_IBitmapEncoderStatics;
template <typename T> struct impl_IBitmapEncoderWithSoftwareBitmap;
template <typename T> struct impl_IBitmapFrame;
template <typename T> struct impl_IBitmapFrameWithSoftwareBitmap;
template <typename T> struct impl_IBitmapProperties;
template <typename T> struct impl_IBitmapPropertiesView;
template <typename T> struct impl_IBitmapTransform;
template <typename T> struct impl_IBitmapTypedValue;
template <typename T> struct impl_IBitmapTypedValueFactory;
template <typename T> struct impl_IPixelDataProvider;
template <typename T> struct impl_ISoftwareBitmap;
template <typename T> struct impl_ISoftwareBitmapFactory;
template <typename T> struct impl_ISoftwareBitmapStatics;

}

namespace Windows::Graphics::Imaging {

enum class BitmapAlphaMode
{
    Premultiplied = 0,
    Straight = 1,
    Ignore = 2,
};

enum class BitmapBufferAccessMode
{
    Read = 0,
    ReadWrite = 1,
    Write = 2,
};

enum class BitmapFlip
{
    None = 0,
    Horizontal = 1,
    Vertical = 2,
};

enum class BitmapInterpolationMode
{
    NearestNeighbor = 0,
    Linear = 1,
    Cubic = 2,
    Fant = 3,
};

enum class BitmapPixelFormat
{
    Unknown = 0,
    Rgba16 = 12,
    Rgba8 = 30,
    Gray16 = 57,
    Gray8 = 62,
    Bgra8 = 87,
    Nv12 = 103,
    Yuy2 = 107,
};

enum class BitmapRotation
{
    None = 0,
    Clockwise90Degrees = 1,
    Clockwise180Degrees = 2,
    Clockwise270Degrees = 3,
};

enum class ColorManagementMode
{
    DoNotColorManage = 0,
    ColorManageToSRgb = 1,
};

enum class ExifOrientationMode
{
    IgnoreExifOrientation = 0,
    RespectExifOrientation = 1,
};

enum class JpegSubsamplingMode
{
    Default = 0,
    Y4Cb2Cr0 = 1,
    Y4Cb2Cr2 = 2,
    Y4Cb4Cr4 = 3,
};

enum class PngFilterMode
{
    Automatic = 0,
    None = 1,
    Sub = 2,
    Up = 3,
    Average = 4,
    Paeth = 5,
    Adaptive = 6,
};

enum class TiffCompressionMode
{
    Automatic = 0,
    None = 1,
    Ccitt3 = 2,
    Ccitt4 = 3,
    Lzw = 4,
    Rle = 5,
    Zip = 6,
    LzwhDifferencing = 7,
};

}

}
