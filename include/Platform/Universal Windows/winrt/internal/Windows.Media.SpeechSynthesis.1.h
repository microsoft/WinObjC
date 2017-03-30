// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.SpeechSynthesis.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Media.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::SpeechSynthesis {

struct __declspec(uuid("7d526ecc-7533-4c3f-85be-888c2baeebdc")) __declspec(novtable) IInstalledVoicesStatic : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllVoices(Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechSynthesis::VoiceInformation> ** value) = 0;
    virtual HRESULT __stdcall get_DefaultVoice(Windows::Media::SpeechSynthesis::IVoiceInformation ** value) = 0;
};

struct __declspec(uuid("83e46e93-244c-4622-ba0b-6229c4d0d65d")) __declspec(novtable) ISpeechSynthesisStream : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Markers(Windows::Foundation::Collections::IVectorView<Windows::Media::IMediaMarker> ** value) = 0;
};

struct __declspec(uuid("ce9f7c76-97f4-4ced-ad68-d51c458e45c6")) __declspec(novtable) ISpeechSynthesizer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SynthesizeTextToStreamAsync(hstring text, Windows::Foundation::IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> ** operation) = 0;
    virtual HRESULT __stdcall abi_SynthesizeSsmlToStreamAsync(hstring Ssml, Windows::Foundation::IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> ** operation) = 0;
    virtual HRESULT __stdcall put_Voice(Windows::Media::SpeechSynthesis::IVoiceInformation * value) = 0;
    virtual HRESULT __stdcall get_Voice(Windows::Media::SpeechSynthesis::IVoiceInformation ** value) = 0;
};

struct __declspec(uuid("b127d6a4-1291-4604-aa9c-83134083352c")) __declspec(novtable) IVoiceInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_Gender(winrt::Windows::Media::SpeechSynthesis::VoiceGender * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> { using default_interface = Windows::Media::SpeechSynthesis::ISpeechSynthesisStream; };
template <> struct traits<Windows::Media::SpeechSynthesis::SpeechSynthesizer> { using default_interface = Windows::Media::SpeechSynthesis::ISpeechSynthesizer; };
template <> struct traits<Windows::Media::SpeechSynthesis::VoiceInformation> { using default_interface = Windows::Media::SpeechSynthesis::IVoiceInformation; };

}

namespace Windows::Media::SpeechSynthesis {

template <typename D>
struct WINRT_EBO impl_IInstalledVoicesStatic
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechSynthesis::VoiceInformation> AllVoices() const;
    Windows::Media::SpeechSynthesis::VoiceInformation DefaultVoice() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechSynthesisStream
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::IMediaMarker> Markers() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechSynthesizer
{
    Windows::Foundation::IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> SynthesizeTextToStreamAsync(hstring_view text) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::SpeechSynthesis::SpeechSynthesisStream> SynthesizeSsmlToStreamAsync(hstring_view Ssml) const;
    void Voice(const Windows::Media::SpeechSynthesis::VoiceInformation & value) const;
    Windows::Media::SpeechSynthesis::VoiceInformation Voice() const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceInformation
{
    hstring DisplayName() const;
    hstring Id() const;
    hstring Language() const;
    hstring Description() const;
    Windows::Media::SpeechSynthesis::VoiceGender Gender() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::SpeechSynthesis::IInstalledVoicesStatic>
{
    using abi = ABI::Windows::Media::SpeechSynthesis::IInstalledVoicesStatic;
    template <typename D> using consume = Windows::Media::SpeechSynthesis::impl_IInstalledVoicesStatic<D>;
};

template <> struct traits<Windows::Media::SpeechSynthesis::ISpeechSynthesisStream>
{
    using abi = ABI::Windows::Media::SpeechSynthesis::ISpeechSynthesisStream;
    template <typename D> using consume = Windows::Media::SpeechSynthesis::impl_ISpeechSynthesisStream<D>;
};

template <> struct traits<Windows::Media::SpeechSynthesis::ISpeechSynthesizer>
{
    using abi = ABI::Windows::Media::SpeechSynthesis::ISpeechSynthesizer;
    template <typename D> using consume = Windows::Media::SpeechSynthesis::impl_ISpeechSynthesizer<D>;
};

template <> struct traits<Windows::Media::SpeechSynthesis::IVoiceInformation>
{
    using abi = ABI::Windows::Media::SpeechSynthesis::IVoiceInformation;
    template <typename D> using consume = Windows::Media::SpeechSynthesis::impl_IVoiceInformation<D>;
};

template <> struct traits<Windows::Media::SpeechSynthesis::SpeechSynthesisStream>
{
    using abi = ABI::Windows::Media::SpeechSynthesis::SpeechSynthesisStream;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechSynthesis.SpeechSynthesisStream"; }
};

template <> struct traits<Windows::Media::SpeechSynthesis::SpeechSynthesizer>
{
    using abi = ABI::Windows::Media::SpeechSynthesis::SpeechSynthesizer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechSynthesis.SpeechSynthesizer"; }
};

template <> struct traits<Windows::Media::SpeechSynthesis::VoiceInformation>
{
    using abi = ABI::Windows::Media::SpeechSynthesis::VoiceInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechSynthesis.VoiceInformation"; }
};

}

}
