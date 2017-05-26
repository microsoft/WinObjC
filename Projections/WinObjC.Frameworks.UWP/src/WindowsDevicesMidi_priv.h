//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsDevicesMidi_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
static ComPtr<ABI::Windows::Devices::Midi::IMidiNoteOffMessageFactory> WDMIMidiNoteOffMessageFactory_inst();
static ComPtr<ABI::Windows::Devices::Midi::IMidiNoteOnMessageFactory> WDMIMidiNoteOnMessageFactory_inst();
static ComPtr<ABI::Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessageFactory> WDMIMidiPolyphonicKeyPressureMessageFactory_inst();
static ComPtr<ABI::Windows::Devices::Midi::IMidiControlChangeMessageFactory> WDMIMidiControlChangeMessageFactory_inst();
static ComPtr<ABI::Windows::Devices::Midi::IMidiProgramChangeMessageFactory> WDMIMidiProgramChangeMessageFactory_inst();
static ComPtr<ABI::Windows::Devices::Midi::IMidiChannelPressureMessageFactory> WDMIMidiChannelPressureMessageFactory_inst();
static ComPtr<ABI::Windows::Devices::Midi::IMidiPitchBendChangeMessageFactory> WDMIMidiPitchBendChangeMessageFactory_inst();
static ComPtr<ABI::Windows::Devices::Midi::IMidiSystemExclusiveMessageFactory> WDMIMidiSystemExclusiveMessageFactory_inst();
static ComPtr<ABI::Windows::Devices::Midi::IMidiTimeCodeMessageFactory> WDMIMidiTimeCodeMessageFactory_inst();
static ComPtr<ABI::Windows::Devices::Midi::IMidiSongPositionPointerMessageFactory> WDMIMidiSongPositionPointerMessageFactory_inst();
static ComPtr<ABI::Windows::Devices::Midi::IMidiSongSelectMessageFactory> WDMIMidiSongSelectMessageFactory_inst();
ComPtr<ABI::Windows::Devices::Midi::IMidiInPortStatics> WDMIMidiInPortStatics_inst();
ComPtr<ABI::Windows::Devices::Midi::IMidiOutPortStatics> WDMIMidiOutPortStatics_inst();
ComPtr<ABI::Windows::Devices::Midi::IMidiSynthesizerStatics> WDMIMidiSynthesizerStatics_inst();

#ifndef __ITypedEventHandler_Windows_Devices_Midi_MidiInPort_Windows_Devices_Midi_MidiMessageReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Midi_MidiInPort_Windows_Devices_Midi_MidiMessageReceivedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Midi_MidiInPort_Windows_Devices_Midi_MidiMessageReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Midi::MidiInPort*,
                                                                       ABI::Windows::Devices::Midi::MidiMessageReceivedEventArgs*>> {
    void (^_delegate)(WDMMidiInPort*, WDMMidiMessageReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Midi_MidiInPort_Windows_Devices_Midi_MidiMessageReceivedEventArgs(
        void (^del)(WDMMidiInPort*, WDMMidiMessageReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Midi_MidiInPort_Windows_Devices_Midi_MidiMessageReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Midi::IMidiInPort* arg0,
                                             ABI::Windows::Devices::Midi::IMidiMessageReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDMMidiInPort>(arg0), _createRtProxy<WDMMidiMessageReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
