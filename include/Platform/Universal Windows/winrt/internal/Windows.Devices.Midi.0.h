// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Midi {

struct IMidiChannelPressureMessage;
struct IMidiChannelPressureMessageFactory;
struct IMidiControlChangeMessage;
struct IMidiControlChangeMessageFactory;
struct IMidiInPort;
struct IMidiInPortStatics;
struct IMidiMessage;
struct IMidiMessageReceivedEventArgs;
struct IMidiNoteOffMessage;
struct IMidiNoteOffMessageFactory;
struct IMidiNoteOnMessage;
struct IMidiNoteOnMessageFactory;
struct IMidiOutPort;
struct IMidiOutPortStatics;
struct IMidiPitchBendChangeMessage;
struct IMidiPitchBendChangeMessageFactory;
struct IMidiPolyphonicKeyPressureMessage;
struct IMidiPolyphonicKeyPressureMessageFactory;
struct IMidiProgramChangeMessage;
struct IMidiProgramChangeMessageFactory;
struct IMidiSongPositionPointerMessage;
struct IMidiSongPositionPointerMessageFactory;
struct IMidiSongSelectMessage;
struct IMidiSongSelectMessageFactory;
struct IMidiSynthesizer;
struct IMidiSynthesizerStatics;
struct IMidiSystemExclusiveMessageFactory;
struct IMidiTimeCodeMessage;
struct IMidiTimeCodeMessageFactory;
struct MidiActiveSensingMessage;
struct MidiChannelPressureMessage;
struct MidiContinueMessage;
struct MidiControlChangeMessage;
struct MidiInPort;
struct MidiMessageReceivedEventArgs;
struct MidiNoteOffMessage;
struct MidiNoteOnMessage;
struct MidiOutPort;
struct MidiPitchBendChangeMessage;
struct MidiPolyphonicKeyPressureMessage;
struct MidiProgramChangeMessage;
struct MidiSongPositionPointerMessage;
struct MidiSongSelectMessage;
struct MidiStartMessage;
struct MidiStopMessage;
struct MidiSynthesizer;
struct MidiSystemExclusiveMessage;
struct MidiSystemResetMessage;
struct MidiTimeCodeMessage;
struct MidiTimingClockMessage;
struct MidiTuneRequestMessage;

}

namespace Windows::Devices::Midi {

struct IMidiChannelPressureMessage;
struct IMidiChannelPressureMessageFactory;
struct IMidiControlChangeMessage;
struct IMidiControlChangeMessageFactory;
struct IMidiInPort;
struct IMidiInPortStatics;
struct IMidiMessage;
struct IMidiMessageReceivedEventArgs;
struct IMidiNoteOffMessage;
struct IMidiNoteOffMessageFactory;
struct IMidiNoteOnMessage;
struct IMidiNoteOnMessageFactory;
struct IMidiOutPort;
struct IMidiOutPortStatics;
struct IMidiPitchBendChangeMessage;
struct IMidiPitchBendChangeMessageFactory;
struct IMidiPolyphonicKeyPressureMessage;
struct IMidiPolyphonicKeyPressureMessageFactory;
struct IMidiProgramChangeMessage;
struct IMidiProgramChangeMessageFactory;
struct IMidiSongPositionPointerMessage;
struct IMidiSongPositionPointerMessageFactory;
struct IMidiSongSelectMessage;
struct IMidiSongSelectMessageFactory;
struct IMidiSynthesizer;
struct IMidiSynthesizerStatics;
struct IMidiSystemExclusiveMessageFactory;
struct IMidiTimeCodeMessage;
struct IMidiTimeCodeMessageFactory;
struct MidiActiveSensingMessage;
struct MidiChannelPressureMessage;
struct MidiContinueMessage;
struct MidiControlChangeMessage;
struct MidiInPort;
struct MidiMessageReceivedEventArgs;
struct MidiNoteOffMessage;
struct MidiNoteOnMessage;
struct MidiOutPort;
struct MidiPitchBendChangeMessage;
struct MidiPolyphonicKeyPressureMessage;
struct MidiProgramChangeMessage;
struct MidiSongPositionPointerMessage;
struct MidiSongSelectMessage;
struct MidiStartMessage;
struct MidiStopMessage;
struct MidiSynthesizer;
struct MidiSystemExclusiveMessage;
struct MidiSystemResetMessage;
struct MidiTimeCodeMessage;
struct MidiTimingClockMessage;
struct MidiTuneRequestMessage;

}

namespace Windows::Devices::Midi {

template <typename T> struct impl_IMidiChannelPressureMessage;
template <typename T> struct impl_IMidiChannelPressureMessageFactory;
template <typename T> struct impl_IMidiControlChangeMessage;
template <typename T> struct impl_IMidiControlChangeMessageFactory;
template <typename T> struct impl_IMidiInPort;
template <typename T> struct impl_IMidiInPortStatics;
template <typename T> struct impl_IMidiMessage;
template <typename T> struct impl_IMidiMessageReceivedEventArgs;
template <typename T> struct impl_IMidiNoteOffMessage;
template <typename T> struct impl_IMidiNoteOffMessageFactory;
template <typename T> struct impl_IMidiNoteOnMessage;
template <typename T> struct impl_IMidiNoteOnMessageFactory;
template <typename T> struct impl_IMidiOutPort;
template <typename T> struct impl_IMidiOutPortStatics;
template <typename T> struct impl_IMidiPitchBendChangeMessage;
template <typename T> struct impl_IMidiPitchBendChangeMessageFactory;
template <typename T> struct impl_IMidiPolyphonicKeyPressureMessage;
template <typename T> struct impl_IMidiPolyphonicKeyPressureMessageFactory;
template <typename T> struct impl_IMidiProgramChangeMessage;
template <typename T> struct impl_IMidiProgramChangeMessageFactory;
template <typename T> struct impl_IMidiSongPositionPointerMessage;
template <typename T> struct impl_IMidiSongPositionPointerMessageFactory;
template <typename T> struct impl_IMidiSongSelectMessage;
template <typename T> struct impl_IMidiSongSelectMessageFactory;
template <typename T> struct impl_IMidiSynthesizer;
template <typename T> struct impl_IMidiSynthesizerStatics;
template <typename T> struct impl_IMidiSystemExclusiveMessageFactory;
template <typename T> struct impl_IMidiTimeCodeMessage;
template <typename T> struct impl_IMidiTimeCodeMessageFactory;

}

namespace Windows::Devices::Midi {

enum class MidiMessageType
{
    None = 0,
    NoteOff = 128,
    NoteOn = 144,
    PolyphonicKeyPressure = 160,
    ControlChange = 176,
    ProgramChange = 192,
    ChannelPressure = 208,
    PitchBendChange = 224,
    SystemExclusive = 240,
    MidiTimeCode = 241,
    SongPositionPointer = 242,
    SongSelect = 243,
    TuneRequest = 246,
    EndSystemExclusive = 247,
    TimingClock = 248,
    Start = 250,
    Continue = 251,
    Stop = 252,
    ActiveSensing = 254,
    SystemReset = 255,
};

}

}
