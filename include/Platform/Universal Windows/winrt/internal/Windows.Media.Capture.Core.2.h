// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Capture.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
#define WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
template <> struct __declspec(uuid("513ef3af-e784-5325-a91e-97c2b8111cf3")) __declspec(novtable) IReference<uint32_t> : impl_IReference<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_bab30230_3dcd_58e2_aac5_a45f3e6f8097
#define WINRT_GENERIC_bab30230_3dcd_58e2_aac5_a45f3e6f8097
template <> struct __declspec(uuid("bab30230-3dcd-58e2-aac5-a45f3e6f8097")) __declspec(novtable) TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs> : impl_TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_2210a640_0e7b_5e8f_a617_2cbb10314a5a
#define WINRT_GENERIC_2210a640_0e7b_5e8f_a617_2cbb10314a5a
template <> struct __declspec(uuid("2210a640-0e7b-5e8f-a617-2cbb10314a5a")) __declspec(novtable) TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Media::Capture::Core::VariablePhotoSequenceCapture, Windows::Foundation::IInspectable> {};
#endif


}

namespace Windows::Media::Capture::Core {

struct IVariablePhotoCapturedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IVariablePhotoCapturedEventArgs>
{
    IVariablePhotoCapturedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IVariablePhotoSequenceCapture :
    Windows::Foundation::IInspectable,
    impl::consume<IVariablePhotoSequenceCapture>
{
    IVariablePhotoSequenceCapture(std::nullptr_t = nullptr) noexcept {}
};

struct IVariablePhotoSequenceCapture2 :
    Windows::Foundation::IInspectable,
    impl::consume<IVariablePhotoSequenceCapture2>
{
    IVariablePhotoSequenceCapture2(std::nullptr_t = nullptr) noexcept {}
};

}

}
