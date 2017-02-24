// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Devices.Midi.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiChannelPressureMessage> : produce_base<D, Windows::Devices::Midi::IMidiChannelPressureMessage>
{
    HRESULT __stdcall get_Channel(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Channel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pressure(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pressure());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiChannelPressureMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiChannelPressureMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiChannelPressureMessage(uint8_t channel, uint8_t pressure, impl::abi_arg_out<Windows::Devices::Midi::IMidiChannelPressureMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiChannelPressureMessage(channel, pressure));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiControlChangeMessage> : produce_base<D, Windows::Devices::Midi::IMidiControlChangeMessage>
{
    HRESULT __stdcall get_Channel(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Channel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Controller(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Controller());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ControlValue(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ControlValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiControlChangeMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiControlChangeMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiControlChangeMessage(uint8_t channel, uint8_t controller, uint8_t controlValue, impl::abi_arg_out<Windows::Devices::Midi::IMidiControlChangeMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiControlChangeMessage(channel, controller, controlValue));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiInPort> : produce_base<D, Windows::Devices::Midi::IMidiInPort>
{
    HRESULT __stdcall add_MessageReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Midi::MidiInPort, Windows::Devices::Midi::MidiMessageReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MessageReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Midi::MidiInPort, Windows::Devices::Midi::MidiMessageReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MessageReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiInPortStatics> : produce_base<D, Windows::Devices::Midi::IMidiInPortStatics>
{
    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiInPort>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiMessage> : produce_base<D, Windows::Devices::Midi::IMidiMessage>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(Windows::Devices::Midi::MidiMessageType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiMessageReceivedEventArgs> : produce_base<D, Windows::Devices::Midi::IMidiMessageReceivedEventArgs>
{
    HRESULT __stdcall get_Message(impl::abi_arg_out<Windows::Devices::Midi::IMidiMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiNoteOffMessage> : produce_base<D, Windows::Devices::Midi::IMidiNoteOffMessage>
{
    HRESULT __stdcall get_Channel(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Channel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Note(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Note());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Velocity(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Velocity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiNoteOffMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiNoteOffMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiNoteOffMessage(uint8_t channel, uint8_t note, uint8_t velocity, impl::abi_arg_out<Windows::Devices::Midi::IMidiNoteOffMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiNoteOffMessage(channel, note, velocity));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiNoteOnMessage> : produce_base<D, Windows::Devices::Midi::IMidiNoteOnMessage>
{
    HRESULT __stdcall get_Channel(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Channel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Note(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Note());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Velocity(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Velocity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiNoteOnMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiNoteOnMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiNoteOnMessage(uint8_t channel, uint8_t note, uint8_t velocity, impl::abi_arg_out<Windows::Devices::Midi::IMidiNoteOnMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiNoteOnMessage(channel, note, velocity));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiOutPort> : produce_base<D, Windows::Devices::Midi::IMidiOutPort>
{
    HRESULT __stdcall abi_SendMessage(impl::abi_arg_in<Windows::Devices::Midi::IMidiMessage> midiMessage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendMessage(*reinterpret_cast<const Windows::Devices::Midi::IMidiMessage *>(&midiMessage));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> midiData) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&midiData));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiOutPortStatics> : produce_base<D, Windows::Devices::Midi::IMidiOutPortStatics>
{
    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::IMidiOutPort>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiPitchBendChangeMessage> : produce_base<D, Windows::Devices::Midi::IMidiPitchBendChangeMessage>
{
    HRESULT __stdcall get_Channel(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Channel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bend(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bend());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiPitchBendChangeMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiPitchBendChangeMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiPitchBendChangeMessage(uint8_t channel, uint16_t bend, impl::abi_arg_out<Windows::Devices::Midi::IMidiPitchBendChangeMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiPitchBendChangeMessage(channel, bend));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessage> : produce_base<D, Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessage>
{
    HRESULT __stdcall get_Channel(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Channel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Note(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Note());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pressure(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pressure());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiPolyphonicKeyPressureMessage(uint8_t channel, uint8_t note, uint8_t pressure, impl::abi_arg_out<Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiPolyphonicKeyPressureMessage(channel, note, pressure));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiProgramChangeMessage> : produce_base<D, Windows::Devices::Midi::IMidiProgramChangeMessage>
{
    HRESULT __stdcall get_Channel(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Channel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Program(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Program());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiProgramChangeMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiProgramChangeMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiProgramChangeMessage(uint8_t channel, uint8_t program, impl::abi_arg_out<Windows::Devices::Midi::IMidiProgramChangeMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiProgramChangeMessage(channel, program));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiSongPositionPointerMessage> : produce_base<D, Windows::Devices::Midi::IMidiSongPositionPointerMessage>
{
    HRESULT __stdcall get_Beats(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Beats());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiSongPositionPointerMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiSongPositionPointerMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiSongPositionPointerMessage(uint16_t beats, impl::abi_arg_out<Windows::Devices::Midi::IMidiSongPositionPointerMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiSongPositionPointerMessage(beats));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiSongSelectMessage> : produce_base<D, Windows::Devices::Midi::IMidiSongSelectMessage>
{
    HRESULT __stdcall get_Song(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Song());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiSongSelectMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiSongSelectMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiSongSelectMessage(uint8_t song, impl::abi_arg_out<Windows::Devices::Midi::IMidiSongSelectMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiSongSelectMessage(song));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiSynthesizer> : produce_base<D, Windows::Devices::Midi::IMidiSynthesizer>
{
    HRESULT __stdcall get_AudioDevice(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioDevice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Volume(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Volume());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Volume(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Volume(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiSynthesizerStatics> : produce_base<D, Windows::Devices::Midi::IMidiSynthesizerStatics>
{
    HRESULT __stdcall abi_CreateAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiSynthesizer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromAudioDeviceAsync(impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> audioDevice, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiSynthesizer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAsync(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&audioDevice)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsSynthesizer(impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> midiDevice, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSynthesizer(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&midiDevice)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiSystemExclusiveMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiSystemExclusiveMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiSystemExclusiveMessage(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> rawData, impl::abi_arg_out<Windows::Devices::Midi::IMidiMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiSystemExclusiveMessage(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&rawData)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiTimeCodeMessage> : produce_base<D, Windows::Devices::Midi::IMidiTimeCodeMessage>
{
    HRESULT __stdcall get_FrameType(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Values(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Values());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Midi::IMidiTimeCodeMessageFactory> : produce_base<D, Windows::Devices::Midi::IMidiTimeCodeMessageFactory>
{
    HRESULT __stdcall abi_CreateMidiTimeCodeMessage(uint8_t frameType, uint8_t values, impl::abi_arg_out<Windows::Devices::Midi::IMidiTimeCodeMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMidiTimeCodeMessage(frameType, values));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Midi {

template <typename D> Windows::Foundation::TimeSpan impl_IMidiMessage<D>::Timestamp() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMidiMessage)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMidiMessage<D>::RawData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMidiMessage)->get_RawData(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiMessageType impl_IMidiMessage<D>::Type() const
{
    Windows::Devices::Midi::MidiMessageType value {};
    check_hresult(WINRT_SHIM(IMidiMessage)->get_Type(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiNoteOffMessage<D>::Channel() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiNoteOffMessage)->get_Channel(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiNoteOffMessage<D>::Note() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiNoteOffMessage)->get_Note(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiNoteOffMessage<D>::Velocity() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiNoteOffMessage)->get_Velocity(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiNoteOnMessage<D>::Channel() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiNoteOnMessage)->get_Channel(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiNoteOnMessage<D>::Note() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiNoteOnMessage)->get_Note(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiNoteOnMessage<D>::Velocity() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiNoteOnMessage)->get_Velocity(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiPolyphonicKeyPressureMessage<D>::Channel() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiPolyphonicKeyPressureMessage)->get_Channel(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiPolyphonicKeyPressureMessage<D>::Note() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiPolyphonicKeyPressureMessage)->get_Note(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiPolyphonicKeyPressureMessage<D>::Pressure() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiPolyphonicKeyPressureMessage)->get_Pressure(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiControlChangeMessage<D>::Channel() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiControlChangeMessage)->get_Channel(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiControlChangeMessage<D>::Controller() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiControlChangeMessage)->get_Controller(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiControlChangeMessage<D>::ControlValue() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiControlChangeMessage)->get_ControlValue(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiProgramChangeMessage<D>::Channel() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiProgramChangeMessage)->get_Channel(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiProgramChangeMessage<D>::Program() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiProgramChangeMessage)->get_Program(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiChannelPressureMessage<D>::Channel() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiChannelPressureMessage)->get_Channel(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiChannelPressureMessage<D>::Pressure() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiChannelPressureMessage)->get_Pressure(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiPitchBendChangeMessage<D>::Channel() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiPitchBendChangeMessage)->get_Channel(&value));
    return value;
}

template <typename D> uint16_t impl_IMidiPitchBendChangeMessage<D>::Bend() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IMidiPitchBendChangeMessage)->get_Bend(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiTimeCodeMessage<D>::FrameType() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiTimeCodeMessage)->get_FrameType(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiTimeCodeMessage<D>::Values() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiTimeCodeMessage)->get_Values(&value));
    return value;
}

template <typename D> uint16_t impl_IMidiSongPositionPointerMessage<D>::Beats() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IMidiSongPositionPointerMessage)->get_Beats(&value));
    return value;
}

template <typename D> uint8_t impl_IMidiSongSelectMessage<D>::Song() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IMidiSongSelectMessage)->get_Song(&value));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiNoteOffMessage impl_IMidiNoteOffMessageFactory<D>::CreateMidiNoteOffMessage(uint8_t channel, uint8_t note, uint8_t velocity) const
{
    Windows::Devices::Midi::MidiNoteOffMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiNoteOffMessageFactory)->abi_CreateMidiNoteOffMessage(channel, note, velocity, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiNoteOnMessage impl_IMidiNoteOnMessageFactory<D>::CreateMidiNoteOnMessage(uint8_t channel, uint8_t note, uint8_t velocity) const
{
    Windows::Devices::Midi::MidiNoteOnMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiNoteOnMessageFactory)->abi_CreateMidiNoteOnMessage(channel, note, velocity, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiPolyphonicKeyPressureMessage impl_IMidiPolyphonicKeyPressureMessageFactory<D>::CreateMidiPolyphonicKeyPressureMessage(uint8_t channel, uint8_t note, uint8_t pressure) const
{
    Windows::Devices::Midi::MidiPolyphonicKeyPressureMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiPolyphonicKeyPressureMessageFactory)->abi_CreateMidiPolyphonicKeyPressureMessage(channel, note, pressure, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiControlChangeMessage impl_IMidiControlChangeMessageFactory<D>::CreateMidiControlChangeMessage(uint8_t channel, uint8_t controller, uint8_t controlValue) const
{
    Windows::Devices::Midi::MidiControlChangeMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiControlChangeMessageFactory)->abi_CreateMidiControlChangeMessage(channel, controller, controlValue, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiProgramChangeMessage impl_IMidiProgramChangeMessageFactory<D>::CreateMidiProgramChangeMessage(uint8_t channel, uint8_t program) const
{
    Windows::Devices::Midi::MidiProgramChangeMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiProgramChangeMessageFactory)->abi_CreateMidiProgramChangeMessage(channel, program, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiChannelPressureMessage impl_IMidiChannelPressureMessageFactory<D>::CreateMidiChannelPressureMessage(uint8_t channel, uint8_t pressure) const
{
    Windows::Devices::Midi::MidiChannelPressureMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiChannelPressureMessageFactory)->abi_CreateMidiChannelPressureMessage(channel, pressure, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiPitchBendChangeMessage impl_IMidiPitchBendChangeMessageFactory<D>::CreateMidiPitchBendChangeMessage(uint8_t channel, uint16_t bend) const
{
    Windows::Devices::Midi::MidiPitchBendChangeMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiPitchBendChangeMessageFactory)->abi_CreateMidiPitchBendChangeMessage(channel, bend, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiSystemExclusiveMessage impl_IMidiSystemExclusiveMessageFactory<D>::CreateMidiSystemExclusiveMessage(const Windows::Storage::Streams::IBuffer & rawData) const
{
    Windows::Devices::Midi::MidiSystemExclusiveMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiSystemExclusiveMessageFactory)->abi_CreateMidiSystemExclusiveMessage(get_abi(rawData), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiTimeCodeMessage impl_IMidiTimeCodeMessageFactory<D>::CreateMidiTimeCodeMessage(uint8_t frameType, uint8_t values) const
{
    Windows::Devices::Midi::MidiTimeCodeMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiTimeCodeMessageFactory)->abi_CreateMidiTimeCodeMessage(frameType, values, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiSongPositionPointerMessage impl_IMidiSongPositionPointerMessageFactory<D>::CreateMidiSongPositionPointerMessage(uint16_t beats) const
{
    Windows::Devices::Midi::MidiSongPositionPointerMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiSongPositionPointerMessageFactory)->abi_CreateMidiSongPositionPointerMessage(beats, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::MidiSongSelectMessage impl_IMidiSongSelectMessageFactory<D>::CreateMidiSongSelectMessage(uint8_t song) const
{
    Windows::Devices::Midi::MidiSongSelectMessage value { nullptr };
    check_hresult(WINRT_SHIM(IMidiSongSelectMessageFactory)->abi_CreateMidiSongSelectMessage(song, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Midi::IMidiMessage impl_IMidiMessageReceivedEventArgs<D>::Message() const
{
    Windows::Devices::Midi::IMidiMessage value;
    check_hresult(WINRT_SHIM(IMidiMessageReceivedEventArgs)->get_Message(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiInPort> impl_IMidiInPortStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiInPort> value;
    check_hresult(WINRT_SHIM(IMidiInPortStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMidiInPortStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMidiInPortStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::IMidiOutPort> impl_IMidiOutPortStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::IMidiOutPort> value;
    check_hresult(WINRT_SHIM(IMidiOutPortStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMidiOutPortStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMidiOutPortStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiSynthesizer> impl_IMidiSynthesizerStatics<D>::CreateAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiSynthesizer> value;
    check_hresult(WINRT_SHIM(IMidiSynthesizerStatics)->abi_CreateAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiSynthesizer> impl_IMidiSynthesizerStatics<D>::CreateAsync(const Windows::Devices::Enumeration::DeviceInformation & audioDevice) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiSynthesizer> value;
    check_hresult(WINRT_SHIM(IMidiSynthesizerStatics)->abi_CreateFromAudioDeviceAsync(get_abi(audioDevice), put_abi(value)));
    return value;
}

template <typename D> bool impl_IMidiSynthesizerStatics<D>::IsSynthesizer(const Windows::Devices::Enumeration::DeviceInformation & midiDevice) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMidiSynthesizerStatics)->abi_IsSynthesizer(get_abi(midiDevice), &value));
    return value;
}

template <typename D> void impl_IMidiOutPort<D>::SendMessage(const Windows::Devices::Midi::IMidiMessage & midiMessage) const
{
    check_hresult(WINRT_SHIM(IMidiOutPort)->abi_SendMessage(get_abi(midiMessage)));
}

template <typename D> void impl_IMidiOutPort<D>::SendBuffer(const Windows::Storage::Streams::IBuffer & midiData) const
{
    check_hresult(WINRT_SHIM(IMidiOutPort)->abi_SendBuffer(get_abi(midiData)));
}

template <typename D> hstring impl_IMidiOutPort<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMidiOutPort)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMidiInPort<D>::MessageReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Midi::MidiInPort, Windows::Devices::Midi::MidiMessageReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMidiInPort)->add_MessageReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMidiInPort> impl_IMidiInPort<D>::MessageReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Midi::MidiInPort, Windows::Devices::Midi::MidiMessageReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMidiInPort>(this, &ABI::Windows::Devices::Midi::IMidiInPort::remove_MessageReceived, MessageReceived(handler));
}

template <typename D> void impl_IMidiInPort<D>::MessageReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMidiInPort)->remove_MessageReceived(token));
}

template <typename D> hstring impl_IMidiInPort<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMidiInPort)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IMidiSynthesizer<D>::AudioDevice() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IMidiSynthesizer)->get_AudioDevice(put_abi(value)));
    return value;
}

template <typename D> double impl_IMidiSynthesizer<D>::Volume() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMidiSynthesizer)->get_Volume(&value));
    return value;
}

template <typename D> void impl_IMidiSynthesizer<D>::Volume(double value) const
{
    check_hresult(WINRT_SHIM(IMidiSynthesizer)->put_Volume(value));
}

inline MidiActiveSensingMessage::MidiActiveSensingMessage() :
    MidiActiveSensingMessage(activate_instance<MidiActiveSensingMessage>())
{}

inline MidiChannelPressureMessage::MidiChannelPressureMessage(uint8_t channel, uint8_t pressure) :
    MidiChannelPressureMessage(get_activation_factory<MidiChannelPressureMessage, IMidiChannelPressureMessageFactory>().CreateMidiChannelPressureMessage(channel, pressure))
{}

inline MidiContinueMessage::MidiContinueMessage() :
    MidiContinueMessage(activate_instance<MidiContinueMessage>())
{}

inline MidiControlChangeMessage::MidiControlChangeMessage(uint8_t channel, uint8_t controller, uint8_t controlValue) :
    MidiControlChangeMessage(get_activation_factory<MidiControlChangeMessage, IMidiControlChangeMessageFactory>().CreateMidiControlChangeMessage(channel, controller, controlValue))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiInPort> MidiInPort::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<MidiInPort, IMidiInPortStatics>().FromIdAsync(deviceId);
}

inline hstring MidiInPort::GetDeviceSelector()
{
    return get_activation_factory<MidiInPort, IMidiInPortStatics>().GetDeviceSelector();
}

inline MidiNoteOffMessage::MidiNoteOffMessage(uint8_t channel, uint8_t note, uint8_t velocity) :
    MidiNoteOffMessage(get_activation_factory<MidiNoteOffMessage, IMidiNoteOffMessageFactory>().CreateMidiNoteOffMessage(channel, note, velocity))
{}

inline MidiNoteOnMessage::MidiNoteOnMessage(uint8_t channel, uint8_t note, uint8_t velocity) :
    MidiNoteOnMessage(get_activation_factory<MidiNoteOnMessage, IMidiNoteOnMessageFactory>().CreateMidiNoteOnMessage(channel, note, velocity))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::IMidiOutPort> MidiOutPort::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<MidiOutPort, IMidiOutPortStatics>().FromIdAsync(deviceId);
}

inline hstring MidiOutPort::GetDeviceSelector()
{
    return get_activation_factory<MidiOutPort, IMidiOutPortStatics>().GetDeviceSelector();
}

inline MidiPitchBendChangeMessage::MidiPitchBendChangeMessage(uint8_t channel, uint16_t bend) :
    MidiPitchBendChangeMessage(get_activation_factory<MidiPitchBendChangeMessage, IMidiPitchBendChangeMessageFactory>().CreateMidiPitchBendChangeMessage(channel, bend))
{}

inline MidiPolyphonicKeyPressureMessage::MidiPolyphonicKeyPressureMessage(uint8_t channel, uint8_t note, uint8_t pressure) :
    MidiPolyphonicKeyPressureMessage(get_activation_factory<MidiPolyphonicKeyPressureMessage, IMidiPolyphonicKeyPressureMessageFactory>().CreateMidiPolyphonicKeyPressureMessage(channel, note, pressure))
{}

inline MidiProgramChangeMessage::MidiProgramChangeMessage(uint8_t channel, uint8_t program) :
    MidiProgramChangeMessage(get_activation_factory<MidiProgramChangeMessage, IMidiProgramChangeMessageFactory>().CreateMidiProgramChangeMessage(channel, program))
{}

inline MidiSongPositionPointerMessage::MidiSongPositionPointerMessage(uint16_t beats) :
    MidiSongPositionPointerMessage(get_activation_factory<MidiSongPositionPointerMessage, IMidiSongPositionPointerMessageFactory>().CreateMidiSongPositionPointerMessage(beats))
{}

inline MidiSongSelectMessage::MidiSongSelectMessage(uint8_t song) :
    MidiSongSelectMessage(get_activation_factory<MidiSongSelectMessage, IMidiSongSelectMessageFactory>().CreateMidiSongSelectMessage(song))
{}

inline MidiStartMessage::MidiStartMessage() :
    MidiStartMessage(activate_instance<MidiStartMessage>())
{}

inline MidiStopMessage::MidiStopMessage() :
    MidiStopMessage(activate_instance<MidiStopMessage>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiSynthesizer> MidiSynthesizer::CreateAsync()
{
    return get_activation_factory<MidiSynthesizer, IMidiSynthesizerStatics>().CreateAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Midi::MidiSynthesizer> MidiSynthesizer::CreateAsync(const Windows::Devices::Enumeration::DeviceInformation & audioDevice)
{
    return get_activation_factory<MidiSynthesizer, IMidiSynthesizerStatics>().CreateAsync(audioDevice);
}

inline bool MidiSynthesizer::IsSynthesizer(const Windows::Devices::Enumeration::DeviceInformation & midiDevice)
{
    return get_activation_factory<MidiSynthesizer, IMidiSynthesizerStatics>().IsSynthesizer(midiDevice);
}

inline MidiSystemExclusiveMessage::MidiSystemExclusiveMessage(const Windows::Storage::Streams::IBuffer & rawData) :
    MidiSystemExclusiveMessage(get_activation_factory<MidiSystemExclusiveMessage, IMidiSystemExclusiveMessageFactory>().CreateMidiSystemExclusiveMessage(rawData))
{}

inline MidiSystemResetMessage::MidiSystemResetMessage() :
    MidiSystemResetMessage(activate_instance<MidiSystemResetMessage>())
{}

inline MidiTimeCodeMessage::MidiTimeCodeMessage(uint8_t frameType, uint8_t values) :
    MidiTimeCodeMessage(get_activation_factory<MidiTimeCodeMessage, IMidiTimeCodeMessageFactory>().CreateMidiTimeCodeMessage(frameType, values))
{}

inline MidiTimingClockMessage::MidiTimingClockMessage() :
    MidiTimingClockMessage(activate_instance<MidiTimingClockMessage>())
{}

inline MidiTuneRequestMessage::MidiTuneRequestMessage() :
    MidiTuneRequestMessage(activate_instance<MidiTuneRequestMessage>())
{}

}

}
#pragma warning(pop)
