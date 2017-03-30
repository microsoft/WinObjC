// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Midi.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cc664f0e_edb1_55c8_9ef7_ec9007e4561c
#define WINRT_GENERIC_cc664f0e_edb1_55c8_9ef7_ec9007e4561c
template <> struct __declspec(uuid("cc664f0e-edb1-55c8-9ef7-ec9007e4561c")) __declspec(novtable) IAsyncOperation<Windows::Devices::Midi::MidiInPort> : impl_IAsyncOperation<Windows::Devices::Midi::MidiInPort> {};
#endif

#ifndef WINRT_GENERIC_32699a4d_1cc0_5a1c_9da6_875197875086
#define WINRT_GENERIC_32699a4d_1cc0_5a1c_9da6_875197875086
template <> struct __declspec(uuid("32699a4d-1cc0-5a1c-9da6-875197875086")) __declspec(novtable) IAsyncOperation<Windows::Devices::Midi::IMidiOutPort> : impl_IAsyncOperation<Windows::Devices::Midi::IMidiOutPort> {};
#endif

#ifndef WINRT_GENERIC_9388b978_13f1_5e37_8133_94430d90dd50
#define WINRT_GENERIC_9388b978_13f1_5e37_8133_94430d90dd50
template <> struct __declspec(uuid("9388b978-13f1-5e37-8133-94430d90dd50")) __declspec(novtable) IAsyncOperation<Windows::Devices::Midi::MidiSynthesizer> : impl_IAsyncOperation<Windows::Devices::Midi::MidiSynthesizer> {};
#endif

#ifndef WINRT_GENERIC_50017240_cc39_5775_8a6b_f6f22386bfca
#define WINRT_GENERIC_50017240_cc39_5775_8a6b_f6f22386bfca
template <> struct __declspec(uuid("50017240-cc39-5775-8a6b-f6f22386bfca")) __declspec(novtable) TypedEventHandler<Windows::Devices::Midi::MidiInPort, Windows::Devices::Midi::MidiMessageReceivedEventArgs> : impl_TypedEventHandler<Windows::Devices::Midi::MidiInPort, Windows::Devices::Midi::MidiMessageReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_6c090fb2_8099_558f_8a92_9a8ea806e6fb
#define WINRT_GENERIC_6c090fb2_8099_558f_8a92_9a8ea806e6fb
template <> struct __declspec(uuid("6c090fb2-8099-558f-8a92-9a8ea806e6fb")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Midi::MidiInPort> : impl_AsyncOperationCompletedHandler<Windows::Devices::Midi::MidiInPort> {};
#endif

#ifndef WINRT_GENERIC_eed37805_2a49_59b4_b4d4_1188c6819122
#define WINRT_GENERIC_eed37805_2a49_59b4_b4d4_1188c6819122
template <> struct __declspec(uuid("eed37805-2a49-59b4-b4d4-1188c6819122")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Midi::IMidiOutPort> : impl_AsyncOperationCompletedHandler<Windows::Devices::Midi::IMidiOutPort> {};
#endif

#ifndef WINRT_GENERIC_5d716335_d087_516f_ad0a_63f61cbcf342
#define WINRT_GENERIC_5d716335_d087_516f_ad0a_63f61cbcf342
template <> struct __declspec(uuid("5d716335-d087-516f-ad0a-63f61cbcf342")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Midi::MidiSynthesizer> : impl_AsyncOperationCompletedHandler<Windows::Devices::Midi::MidiSynthesizer> {};
#endif


}

namespace Windows::Devices::Midi {

struct IMidiChannelPressureMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiChannelPressureMessage>,
    impl::require<IMidiChannelPressureMessage, Windows::Devices::Midi::IMidiMessage>
{
    IMidiChannelPressureMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiChannelPressureMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiChannelPressureMessageFactory>
{
    IMidiChannelPressureMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiControlChangeMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiControlChangeMessage>,
    impl::require<IMidiControlChangeMessage, Windows::Devices::Midi::IMidiMessage>
{
    IMidiControlChangeMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiControlChangeMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiControlChangeMessageFactory>
{
    IMidiControlChangeMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiInPort :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiInPort>,
    impl::require<IMidiInPort, Windows::Foundation::IClosable>
{
    IMidiInPort(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiInPortStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiInPortStatics>
{
    IMidiInPortStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiMessage>
{
    IMidiMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiMessageReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiMessageReceivedEventArgs>
{
    IMidiMessageReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiNoteOffMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiNoteOffMessage>,
    impl::require<IMidiNoteOffMessage, Windows::Devices::Midi::IMidiMessage>
{
    IMidiNoteOffMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiNoteOffMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiNoteOffMessageFactory>
{
    IMidiNoteOffMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiNoteOnMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiNoteOnMessage>,
    impl::require<IMidiNoteOnMessage, Windows::Devices::Midi::IMidiMessage>
{
    IMidiNoteOnMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiNoteOnMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiNoteOnMessageFactory>
{
    IMidiNoteOnMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiOutPort :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiOutPort>,
    impl::require<IMidiOutPort, Windows::Foundation::IClosable>
{
    IMidiOutPort(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiOutPortStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiOutPortStatics>
{
    IMidiOutPortStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiPitchBendChangeMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiPitchBendChangeMessage>,
    impl::require<IMidiPitchBendChangeMessage, Windows::Devices::Midi::IMidiMessage>
{
    IMidiPitchBendChangeMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiPitchBendChangeMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiPitchBendChangeMessageFactory>
{
    IMidiPitchBendChangeMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiPolyphonicKeyPressureMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiPolyphonicKeyPressureMessage>,
    impl::require<IMidiPolyphonicKeyPressureMessage, Windows::Devices::Midi::IMidiMessage>
{
    IMidiPolyphonicKeyPressureMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiPolyphonicKeyPressureMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiPolyphonicKeyPressureMessageFactory>
{
    IMidiPolyphonicKeyPressureMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiProgramChangeMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiProgramChangeMessage>,
    impl::require<IMidiProgramChangeMessage, Windows::Devices::Midi::IMidiMessage>
{
    IMidiProgramChangeMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiProgramChangeMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiProgramChangeMessageFactory>
{
    IMidiProgramChangeMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiSongPositionPointerMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiSongPositionPointerMessage>,
    impl::require<IMidiSongPositionPointerMessage, Windows::Devices::Midi::IMidiMessage>
{
    IMidiSongPositionPointerMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiSongPositionPointerMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiSongPositionPointerMessageFactory>
{
    IMidiSongPositionPointerMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiSongSelectMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiSongSelectMessage>,
    impl::require<IMidiSongSelectMessage, Windows::Devices::Midi::IMidiMessage>
{
    IMidiSongSelectMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiSongSelectMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiSongSelectMessageFactory>
{
    IMidiSongSelectMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiSynthesizer :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiSynthesizer>,
    impl::require<IMidiSynthesizer, Windows::Devices::Midi::IMidiOutPort, Windows::Foundation::IClosable>
{
    IMidiSynthesizer(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiSynthesizerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiSynthesizerStatics>
{
    IMidiSynthesizerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiSystemExclusiveMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiSystemExclusiveMessageFactory>
{
    IMidiSystemExclusiveMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiTimeCodeMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiTimeCodeMessage>,
    impl::require<IMidiTimeCodeMessage, Windows::Devices::Midi::IMidiMessage>
{
    IMidiTimeCodeMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IMidiTimeCodeMessageFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMidiTimeCodeMessageFactory>
{
    IMidiTimeCodeMessageFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
