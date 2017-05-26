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

// WindowsDevicesMidi.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Midi.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesMidi.h"
#include "WindowsDevicesMidi_priv.h"

@implementation WDMIMidiMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMIMidiOutPort

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiOutPort> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)sendMessage:(RTObject<WDMIMidiMessage>*)midiMessage {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiOutPort>(self);
    THROW_NS_IF_FAILED(_comInst->SendMessage(_getRtInterface<ABI::Windows::Devices::Midi::IMidiMessage>(midiMessage).Get()));
}

- (void)sendBuffer:(RTObject<WSSIBuffer>*)midiData {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiOutPort>(self);
    THROW_NS_IF_FAILED(_comInst->SendBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(midiData).Get()));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiOutPort>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDMMidiNoteOffMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiNoteOffMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiNoteOffMessageFactory> WDMIMidiNoteOffMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiNoteOffMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiNoteOffMessage").Get(), &inst));
    return inst;
}

+ (WDMMidiNoteOffMessage*)makeMidiNoteOffMessage:(uint8_t)channel note:(uint8_t)note velocity:(uint8_t)velocity {
    ComPtr<ABI::Windows::Devices::Midi::IMidiNoteOffMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiNoteOffMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiNoteOffMessage(channel, note, velocity, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiNoteOffMessage>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)channel {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiNoteOffMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Channel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)note {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiNoteOffMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Note(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)velocity {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiNoteOffMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Velocity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiNoteOnMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiNoteOnMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiNoteOnMessageFactory> WDMIMidiNoteOnMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiNoteOnMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiNoteOnMessage").Get(), &inst));
    return inst;
}

+ (WDMMidiNoteOnMessage*)makeMidiNoteOnMessage:(uint8_t)channel note:(uint8_t)note velocity:(uint8_t)velocity {
    ComPtr<ABI::Windows::Devices::Midi::IMidiNoteOnMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiNoteOnMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiNoteOnMessage(channel, note, velocity, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiNoteOnMessage>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)channel {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiNoteOnMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Channel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)note {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiNoteOnMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Note(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)velocity {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiNoteOnMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Velocity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiPolyphonicKeyPressureMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessageFactory> WDMIMidiPolyphonicKeyPressureMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessageFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Midi.MidiPolyphonicKeyPressureMessage").Get(), &inst));
    return inst;
}

+ (WDMMidiPolyphonicKeyPressureMessage*)makeMidiPolyphonicKeyPressureMessage:(uint8_t)channel
                                                                        note:(uint8_t)note
                                                                    pressure:(uint8_t)pressure {
    ComPtr<ABI::Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiPolyphonicKeyPressureMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiPolyphonicKeyPressureMessage(channel, note, pressure, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiPolyphonicKeyPressureMessage>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)channel {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Channel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)note {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Note(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)pressure {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiPolyphonicKeyPressureMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pressure(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiControlChangeMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiControlChangeMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiControlChangeMessageFactory> WDMIMidiControlChangeMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiControlChangeMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiControlChangeMessage").Get(),
                                                       &inst));
    return inst;
}

+ (WDMMidiControlChangeMessage*)makeMidiControlChangeMessage:(uint8_t)channel
                                                  controller:(uint8_t)controller
                                                controlValue:(uint8_t)controlValue {
    ComPtr<ABI::Windows::Devices::Midi::IMidiControlChangeMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiControlChangeMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiControlChangeMessage(channel, controller, controlValue, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiControlChangeMessage>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)channel {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiControlChangeMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Channel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)controller {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiControlChangeMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Controller(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)controlValue {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiControlChangeMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiProgramChangeMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiProgramChangeMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiProgramChangeMessageFactory> WDMIMidiProgramChangeMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiProgramChangeMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiProgramChangeMessage").Get(),
                                                       &inst));
    return inst;
}

+ (WDMMidiProgramChangeMessage*)makeMidiProgramChangeMessage:(uint8_t)channel program:(uint8_t)program {
    ComPtr<ABI::Windows::Devices::Midi::IMidiProgramChangeMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiProgramChangeMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiProgramChangeMessage(channel, program, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiProgramChangeMessage>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)channel {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiProgramChangeMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Channel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)program {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiProgramChangeMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Program(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiChannelPressureMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiChannelPressureMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiChannelPressureMessageFactory> WDMIMidiChannelPressureMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiChannelPressureMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiChannelPressureMessage").Get(),
                                                       &inst));
    return inst;
}

+ (WDMMidiChannelPressureMessage*)makeMidiChannelPressureMessage:(uint8_t)channel pressure:(uint8_t)pressure {
    ComPtr<ABI::Windows::Devices::Midi::IMidiChannelPressureMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiChannelPressureMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiChannelPressureMessage(channel, pressure, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiChannelPressureMessage>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)channel {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiChannelPressureMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Channel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)pressure {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiChannelPressureMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pressure(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiPitchBendChangeMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiPitchBendChangeMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiPitchBendChangeMessageFactory> WDMIMidiPitchBendChangeMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiPitchBendChangeMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiPitchBendChangeMessage").Get(),
                                                       &inst));
    return inst;
}

+ (WDMMidiPitchBendChangeMessage*)makeMidiPitchBendChangeMessage:(uint8_t)channel bend:(unsigned short)bend {
    ComPtr<ABI::Windows::Devices::Midi::IMidiPitchBendChangeMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiPitchBendChangeMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiPitchBendChangeMessage(channel, bend, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiPitchBendChangeMessage>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)channel {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiPitchBendChangeMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Channel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)bend {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiPitchBendChangeMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bend(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiSystemExclusiveMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiSystemExclusiveMessageFactory> WDMIMidiSystemExclusiveMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiSystemExclusiveMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiSystemExclusiveMessage").Get(),
                                                       &inst));
    return inst;
}

+ (WDMMidiSystemExclusiveMessage*)makeMidiSystemExclusiveMessage:(RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiSystemExclusiveMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiSystemExclusiveMessage(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(rawData).Get(),
                                                                  unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiSystemExclusiveMessage>(unmarshalledReturn.Get()) retain];
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiTimeCodeMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiTimeCodeMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiTimeCodeMessageFactory> WDMIMidiTimeCodeMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiTimeCodeMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiTimeCodeMessage").Get(), &inst));
    return inst;
}

+ (WDMMidiTimeCodeMessage*)makeMidiTimeCodeMessage:(uint8_t)frameType values:(uint8_t)values {
    ComPtr<ABI::Windows::Devices::Midi::IMidiTimeCodeMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiTimeCodeMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiTimeCodeMessage(frameType, values, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiTimeCodeMessage>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)frameType {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiTimeCodeMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint8_t)values {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiTimeCodeMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Values(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiSongPositionPointerMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiSongPositionPointerMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiSongPositionPointerMessageFactory> WDMIMidiSongPositionPointerMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiSongPositionPointerMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiSongPositionPointerMessage").Get(),
                                                       &inst));
    return inst;
}

+ (WDMMidiSongPositionPointerMessage*)makeMidiSongPositionPointerMessage:(unsigned short)beats {
    ComPtr<ABI::Windows::Devices::Midi::IMidiSongPositionPointerMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiSongPositionPointerMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiSongPositionPointerMessage(beats, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiSongPositionPointerMessage>(unmarshalledReturn.Get()) retain];
}

- (unsigned short)beats {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiSongPositionPointerMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Beats(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiSongSelectMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiSongSelectMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Midi::IMidiSongSelectMessageFactory> WDMIMidiSongSelectMessageFactory_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiSongSelectMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiSongSelectMessage").Get(), &inst));
    return inst;
}

+ (WDMMidiSongSelectMessage*)makeMidiSongSelectMessage:(uint8_t)song {
    ComPtr<ABI::Windows::Devices::Midi::IMidiSongSelectMessage> unmarshalledReturn;
    auto _comInst = WDMIMidiSongSelectMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMidiSongSelectMessage(song, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDMMidiSongSelectMessage>(unmarshalledReturn.Get()) retain];
}

- (uint8_t)song {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiSongSelectMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Song(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiTuneRequestMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Midi.MidiTuneRequestMessage").Get(), &out));
    return [_createRtProxy<WDMMidiTuneRequestMessage>(out.Get()) retain];
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiTimingClockMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Midi.MidiTimingClockMessage").Get(), &out));
    return [_createRtProxy<WDMMidiTimingClockMessage>(out.Get()) retain];
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiStartMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Midi.MidiStartMessage").Get(), &out));
    return [_createRtProxy<WDMMidiStartMessage>(out.Get()) retain];
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiContinueMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Midi.MidiContinueMessage").Get(), &out));
    return [_createRtProxy<WDMMidiContinueMessage>(out.Get()) retain];
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiStopMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Midi.MidiStopMessage").Get(), &out));
    return [_createRtProxy<WDMMidiStopMessage>(out.Get()) retain];
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiActiveSensingMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Midi.MidiActiveSensingMessage").Get(), &out));
    return [_createRtProxy<WDMMidiActiveSensingMessage>(out.Get()) retain];
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiSystemResetMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.Midi.MidiSystemResetMessage").Get(), &out));
    return [_createRtProxy<WDMMidiSystemResetMessage>(out.Get()) retain];
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)rawData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDMMidiMessageType)type {
    ABI::Windows::Devices::Midi::MidiMessageType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WDMMidiMessageType)unmarshalledReturn;
}

@end

@implementation WDMMidiMessageReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessageReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WDMIMidiMessage>*)message {
    ComPtr<ABI::Windows::Devices::Midi::IMidiMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiMessageReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDMIMidiMessage>(unmarshalledReturn.Get());
}

@end

@implementation WDMMidiInPort

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiInPort> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Midi::IMidiInPortStatics> WDMIMidiInPortStatics_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiInPortStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiInPort").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDMMidiInPort*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Midi::MidiInPort*>> unmarshalledReturn;
    auto _comInst = WDMIMidiInPortStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Midi::MidiInPort*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Midi::MidiInPort*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Midi::IMidiInPort> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDMMidiInPort>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDMIMidiInPortStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (EventRegistrationToken)addMessageReceivedEvent:(void (^)(WDMMidiInPort*, WDMMidiMessageReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiInPort>(self);
    THROW_NS_IF_FAILED(_comInst->add_MessageReceived(
        Make<ITypedEventHandler_Windows_Devices_Midi_MidiInPort_Windows_Devices_Midi_MidiMessageReceivedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMessageReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiInPort>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MessageReceived(token));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiInPort>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDMMidiOutPort

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiOutPort> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Midi::IMidiOutPortStatics> WDMIMidiOutPortStatics_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiOutPortStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiOutPort").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(RTObject<WDMIMidiOutPort>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Midi::IMidiOutPort*>> unmarshalledReturn;
    auto _comInst = WDMIMidiOutPortStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Midi::IMidiOutPort*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Midi::IMidiOutPort*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Midi::IMidiOutPort> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDMIMidiOutPort>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDMIMidiOutPortStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)sendMessage:(RTObject<WDMIMidiMessage>*)midiMessage {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiOutPort>(self);
    THROW_NS_IF_FAILED(_comInst->SendMessage(_getRtInterface<ABI::Windows::Devices::Midi::IMidiMessage>(midiMessage).Get()));
}

- (void)sendBuffer:(RTObject<WSSIBuffer>*)midiData {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiOutPort>(self);
    THROW_NS_IF_FAILED(_comInst->SendBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(midiData).Get()));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiOutPort>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDMMidiSynthesizer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Midi::IMidiSynthesizer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Midi::IMidiSynthesizerStatics> WDMIMidiSynthesizerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Midi::IMidiSynthesizerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Midi.MidiSynthesizer").Get(), &inst));
    return inst;
}

+ (void)createAsyncWithSuccess:(void (^)(WDMMidiSynthesizer*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Midi::MidiSynthesizer*>> unmarshalledReturn;
    auto _comInst = WDMIMidiSynthesizerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Midi::MidiSynthesizer*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Midi::MidiSynthesizer*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Midi::IMidiSynthesizer> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDMMidiSynthesizer>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)createFromAudioDeviceAsync:(WDEDeviceInformation*)audioDevice
                           success:(void (^)(WDMMidiSynthesizer*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Midi::MidiSynthesizer*>> unmarshalledReturn;
    auto _comInst = WDMIMidiSynthesizerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromAudioDeviceAsync(_getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(audioDevice).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Midi::MidiSynthesizer*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Midi::MidiSynthesizer*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Midi::IMidiSynthesizer> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDMMidiSynthesizer>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (BOOL)isSynthesizer:(WDEDeviceInformation*)midiDevice {
    boolean unmarshalledReturn;
    auto _comInst = WDMIMidiSynthesizerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsSynthesizer(_getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(midiDevice).Get(),
                                               &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDEDeviceInformation*)audioDevice {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiSynthesizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (double)volume {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiSynthesizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Volume(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setVolume:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiSynthesizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_Volume(value));
}

- (void)sendMessage:(RTObject<WDMIMidiMessage>*)midiMessage {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiOutPort>(self);
    THROW_NS_IF_FAILED(_comInst->SendMessage(_getRtInterface<ABI::Windows::Devices::Midi::IMidiMessage>(midiMessage).Get()));
}

- (void)sendBuffer:(RTObject<WSSIBuffer>*)midiData {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiOutPort>(self);
    THROW_NS_IF_FAILED(_comInst->SendBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(midiData).Get()));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Midi::IMidiOutPort>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end
