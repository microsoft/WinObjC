// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::SpeechSynthesis {

struct IInstalledVoicesStatic;
struct ISpeechSynthesisStream;
struct ISpeechSynthesizer;
struct IVoiceInformation;
struct SpeechSynthesisStream;
struct SpeechSynthesizer;
struct VoiceInformation;

}

namespace Windows::Media::SpeechSynthesis {

struct IInstalledVoicesStatic;
struct ISpeechSynthesisStream;
struct ISpeechSynthesizer;
struct IVoiceInformation;
struct SpeechSynthesisStream;
struct SpeechSynthesizer;
struct VoiceInformation;

}

namespace Windows::Media::SpeechSynthesis {

template <typename T> struct impl_IInstalledVoicesStatic;
template <typename T> struct impl_ISpeechSynthesisStream;
template <typename T> struct impl_ISpeechSynthesizer;
template <typename T> struct impl_IVoiceInformation;

}

namespace Windows::Media::SpeechSynthesis {

enum class VoiceGender
{
    Male = 0,
    Female = 1,
};

}

}
