// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.SpeechSynthesis.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b543562c_02b1_5824_80a8_9854130cdadd
#define WINRT_GENERIC_b543562c_02b1_5824_80a8_9854130cdadd
template <> struct __declspec(uuid("b543562c-02b1-5824-80a8-9854130cdadd")) __declspec(novtable) IVectorView<Windows::Media::IMediaMarker> : impl_IVectorView<Windows::Media::IMediaMarker> {};
#endif

#ifndef WINRT_GENERIC_ee8d63ce_51ac_5984_891b_d232fa7f6453
#define WINRT_GENERIC_ee8d63ce_51ac_5984_891b_d232fa7f6453
template <> struct __declspec(uuid("ee8d63ce-51ac-5984-891b-d232fa7f6453")) __declspec(novtable) IVectorView<Windows::Media::SpeechSynthesis::VoiceInformation> : impl_IVectorView<Windows::Media::SpeechSynthesis::VoiceInformation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_df9d48ad_9cea_560c_9edc_cb8852cb55e3
#define WINRT_GENERIC_df9d48ad_9cea_560c_9edc_cb8852cb55e3
template <> struct __declspec(uuid("df9d48ad-9cea-560c-9edc-cb8852cb55e3")) __declspec(novtable) IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> : impl_IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f464661e_88bc_5cea_93cd_0c123f17d258
#define WINRT_GENERIC_f464661e_88bc_5cea_93cd_0c123f17d258
template <> struct __declspec(uuid("f464661e-88bc-5cea-93cd-0c123f17d258")) __declspec(novtable) IIterator<Windows::Media::IMediaMarker> : impl_IIterator<Windows::Media::IMediaMarker> {};
#endif

#ifndef WINRT_GENERIC_a1c0a397_0364_5e4c_9dca_7cd7011bd114
#define WINRT_GENERIC_a1c0a397_0364_5e4c_9dca_7cd7011bd114
template <> struct __declspec(uuid("a1c0a397-0364-5e4c-9dca-7cd7011bd114")) __declspec(novtable) IIterable<Windows::Media::IMediaMarker> : impl_IIterable<Windows::Media::IMediaMarker> {};
#endif

#ifndef WINRT_GENERIC_12d40a27_ae8d_5fb0_8fed_00165d59c6ab
#define WINRT_GENERIC_12d40a27_ae8d_5fb0_8fed_00165d59c6ab
template <> struct __declspec(uuid("12d40a27-ae8d-5fb0-8fed-00165d59c6ab")) __declspec(novtable) IIterator<Windows::Media::SpeechSynthesis::VoiceInformation> : impl_IIterator<Windows::Media::SpeechSynthesis::VoiceInformation> {};
#endif

#ifndef WINRT_GENERIC_3c33bb52_bd98_5c8c_adee_ee8da0628efc
#define WINRT_GENERIC_3c33bb52_bd98_5c8c_adee_ee8da0628efc
template <> struct __declspec(uuid("3c33bb52-bd98-5c8c-adee-ee8da0628efc")) __declspec(novtable) IIterable<Windows::Media::SpeechSynthesis::VoiceInformation> : impl_IIterable<Windows::Media::SpeechSynthesis::VoiceInformation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c972b996_6165_50d4_af60_a8c3df51d092
#define WINRT_GENERIC_c972b996_6165_50d4_af60_a8c3df51d092
template <> struct __declspec(uuid("c972b996-6165-50d4-af60-a8c3df51d092")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> : impl_AsyncOperationCompletedHandler<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> {};
#endif


}

namespace Windows::Media::SpeechSynthesis {

struct IInstalledVoicesStatic :
    Windows::Foundation::IInspectable,
    impl::consume<IInstalledVoicesStatic>
{
    IInstalledVoicesStatic(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechSynthesisStream :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechSynthesisStream>,
    impl::require<ISpeechSynthesisStream, Windows::Foundation::IClosable, Windows::Storage::Streams::IContentTypeProvider, Windows::Storage::Streams::IInputStream, Windows::Storage::Streams::IOutputStream, Windows::Storage::Streams::IRandomAccessStream, Windows::Storage::Streams::IRandomAccessStreamWithContentType>
{
    ISpeechSynthesisStream(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechSynthesizer :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechSynthesizer>
{
    ISpeechSynthesizer(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceInformation>
{
    IVoiceInformation(std::nullptr_t = nullptr) noexcept {}
};

}

}
