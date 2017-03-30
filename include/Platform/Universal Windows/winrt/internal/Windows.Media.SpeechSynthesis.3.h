// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.SpeechSynthesis.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::SpeechSynthesis {

struct WINRT_EBO SpeechSynthesisStream :
    Windows::Media::SpeechSynthesis::ISpeechSynthesisStream
{
    SpeechSynthesisStream(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpeechSynthesizer :
    Windows::Media::SpeechSynthesis::ISpeechSynthesizer,
    impl::require<SpeechSynthesizer, Windows::Foundation::IClosable>
{
    SpeechSynthesizer(std::nullptr_t) noexcept {}
    SpeechSynthesizer();
    static Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechSynthesis::VoiceInformation> AllVoices();
    static Windows::Media::SpeechSynthesis::VoiceInformation DefaultVoice();
};

struct WINRT_EBO VoiceInformation :
    Windows::Media::SpeechSynthesis::IVoiceInformation
{
    VoiceInformation(std::nullptr_t) noexcept {}
};

}

}
