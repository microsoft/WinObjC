//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <StubReturn.h>
#import <CoreMIDI/MIDIServices.h>

const CFStringRef kMIDIPropertyAdvanceScheduleTimeMuSec = CFSTR("kMIDIPropertyAdvanceScheduleTimeMuSec");
const CFStringRef kMIDIPropertyCanRoute = CFSTR("kMIDIPropertyCanRoute");
const CFStringRef kMIDIPropertyConnectionUniqueID = CFSTR("kMIDIPropertyConnectionUniqueID");
const CFStringRef kMIDIPropertyDeviceID = CFSTR("kMIDIPropertyDeviceID");
const CFStringRef kMIDIPropertyDisplayName = CFSTR("kMIDIPropertyDisplayName");
const CFStringRef kMIDIPropertyDriverDeviceEditorApp = CFSTR("kMIDIPropertyDriverDeviceEditorApp");
const CFStringRef kMIDIPropertyDriverOwner = CFSTR("kMIDIPropertyDriverOwner");
const CFStringRef kMIDIPropertyDriverVersion = CFSTR("kMIDIPropertyDriverVersion");
const CFStringRef kMIDIPropertyImage = CFSTR("kMIDIPropertyImage");
const CFStringRef kMIDIPropertyIsBroadcast = CFSTR("kMIDIPropertyIsBroadcast");
const CFStringRef kMIDIPropertyIsDrumMachine = CFSTR("kMIDIPropertyIsDrumMachine");
const CFStringRef kMIDIPropertyIsEffectUnit = CFSTR("kMIDIPropertyIsEffectUnit");
const CFStringRef kMIDIPropertyIsEmbeddedEntity = CFSTR("kMIDIPropertyIsEmbeddedEntity");
const CFStringRef kMIDIPropertyIsMixer = CFSTR("kMIDIPropertyIsMixer");
const CFStringRef kMIDIPropertyIsSampler = CFSTR("kMIDIPropertyIsSampler");
const CFStringRef kMIDIPropertyManufacturer = CFSTR("kMIDIPropertyManufacturer");
const CFStringRef kMIDIPropertyMaxReceiveChannels = CFSTR("kMIDIPropertyMaxReceiveChannels");
const CFStringRef kMIDIPropertyMaxSysExSpeed = CFSTR("kMIDIPropertyMaxSysExSpeed");
const CFStringRef kMIDIPropertyMaxTransmitChannels = CFSTR("kMIDIPropertyMaxTransmitChannels");
const CFStringRef kMIDIPropertyModel = CFSTR("kMIDIPropertyModel");
const CFStringRef kMIDIPropertyName = CFSTR("kMIDIPropertyName");
const CFStringRef kMIDIPropertyNameConfiguration = CFSTR("kMIDIPropertyNameConfiguration");
const CFStringRef kMIDIPropertyOffline = CFSTR("kMIDIPropertyOffline");
const CFStringRef kMIDIPropertyPanDisruptsStereo = CFSTR("kMIDIPropertyPanDisruptsStereo");
const CFStringRef kMIDIPropertyPrivate = CFSTR("kMIDIPropertyPrivate");
const CFStringRef kMIDIPropertyReceiveChannels = CFSTR("kMIDIPropertyReceiveChannels");
const CFStringRef kMIDIPropertyReceivesBankSelectLSB = CFSTR("kMIDIPropertyReceivesBankSelectLSB");
const CFStringRef kMIDIPropertyReceivesBankSelectMSB = CFSTR("kMIDIPropertyReceivesBankSelectMSB");
const CFStringRef kMIDIPropertyReceivesClock = CFSTR("kMIDIPropertyReceivesClock");
const CFStringRef kMIDIPropertyReceivesMTC = CFSTR("kMIDIPropertyReceivesMTC");
const CFStringRef kMIDIPropertyReceivesNotes = CFSTR("kMIDIPropertyReceivesNotes");
const CFStringRef kMIDIPropertyReceivesProgramChanges = CFSTR("kMIDIPropertyReceivesProgramChanges");
const CFStringRef kMIDIPropertySingleRealtimeEntity = CFSTR("kMIDIPropertySingleRealtimeEntity");
const CFStringRef kMIDIPropertySupportsGeneralMIDI = CFSTR("kMIDIPropertySupportsGeneralMIDI");
const CFStringRef kMIDIPropertySupportsMMC = CFSTR("kMIDIPropertySupportsMMC");
const CFStringRef kMIDIPropertySupportsShowControl = CFSTR("kMIDIPropertySupportsShowControl");
const CFStringRef kMIDIPropertyTransmitChannels = CFSTR("kMIDIPropertyTransmitChannels");
const CFStringRef kMIDIPropertyTransmitsBankSelectLSB = CFSTR("kMIDIPropertyTransmitsBankSelectLSB");
const CFStringRef kMIDIPropertyTransmitsBankSelectMSB = CFSTR("kMIDIPropertyTransmitsBankSelectMSB");
const CFStringRef kMIDIPropertyTransmitsClock = CFSTR("kMIDIPropertyTransmitsClock");
const CFStringRef kMIDIPropertyTransmitsMTC = CFSTR("kMIDIPropertyTransmitsMTC");
const CFStringRef kMIDIPropertyTransmitsNotes = CFSTR("kMIDIPropertyTransmitsNotes");
const CFStringRef kMIDIPropertyTransmitsProgramChanges = CFSTR("kMIDIPropertyTransmitsProgramChanges");
const CFStringRef kMIDIPropertyUniqueID = CFSTR("kMIDIPropertyUniqueID");

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIInputPortCreate(MIDIClientRef client, CFStringRef portName, MIDIReadProc readProc, void* refCon, MIDIPortRef* outPort) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIOutputPortCreate(MIDIClientRef client, CFStringRef portName, MIDIPortRef* outPort) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIPortConnectSource(MIDIPortRef port, MIDIEndpointRef source, void* connRefCon) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIPortDisconnectSource(MIDIPortRef port, MIDIEndpointRef source) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIPortDispose(MIDIPortRef port) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
MIDIPacket* MIDIPacketListAdd(
    MIDIPacketList* pktlist, ByteCount listSize, MIDIPacket* curPacket, MIDITimeStamp time, ByteCount nData, const Byte* data) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
MIDIPacket* MIDIPacketListInit(MIDIPacketList* pktlist) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
MIDIPacket* MIDIPacketNext(const MIDIPacket* pkt) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectFindByUniqueID(MIDIUniqueID inUniqueID, MIDIObjectRef* outObject, MIDIObjectType* outObjectType) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectGetDataProperty(MIDIObjectRef obj, CFStringRef propertyID, CFDataRef _Nullable* outData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectGetDictionaryProperty(MIDIObjectRef obj, CFStringRef propertyID, CFDictionaryRef _Nullable* outDict) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectGetIntegerProperty(MIDIObjectRef obj, CFStringRef propertyID, SInt32* outValue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectGetProperties(MIDIObjectRef obj, CFPropertyListRef _Nullable* outProperties, Boolean deep) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectGetStringProperty(MIDIObjectRef obj, CFStringRef propertyID, CFStringRef _Nullable* str) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectRemoveProperty(MIDIObjectRef obj, CFStringRef propertyID) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectSetDataProperty(MIDIObjectRef obj, CFStringRef propertyID, CFDataRef data) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectSetDictionaryProperty(MIDIObjectRef obj, CFStringRef propertyID, CFDictionaryRef dict) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectSetIntegerProperty(MIDIObjectRef obj, CFStringRef propertyID, SInt32 value) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIObjectSetStringProperty(MIDIObjectRef obj, CFStringRef propertyID, CFStringRef str) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIFlushOutput(MIDIEndpointRef dest) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIReceived(MIDIEndpointRef src, const MIDIPacketList* pktlist) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIRestart() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDISend(MIDIPortRef port, MIDIEndpointRef dest, const MIDIPacketList* pktlist) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDISendSysex(MIDISysexSendRequest* request) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
MIDIDeviceRef MIDIGetExternalDevice(ItemCount deviceIndex0) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
ItemCount MIDIGetNumberOfExternalDevices() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
MIDIEndpointRef MIDIEntityGetDestination(MIDIEntityRef entity, ItemCount destIndex0) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIEntityGetDevice(MIDIEntityRef inEntity, MIDIDeviceRef* outDevice) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
ItemCount MIDIEntityGetNumberOfDestinations(MIDIEntityRef entity) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
ItemCount MIDIEntityGetNumberOfSources(MIDIEntityRef entity) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
MIDIEndpointRef MIDIEntityGetSource(MIDIEntityRef entity, ItemCount sourceIndex0) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIDestinationCreate(MIDIClientRef client, CFStringRef name, MIDIReadProc readProc, void* refCon, MIDIEndpointRef* outDest) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIEndpointDispose(MIDIEndpointRef endpt) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIEndpointGetEntity(MIDIEndpointRef inEndpoint, MIDIEntityRef* outEntity) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
MIDIEndpointRef MIDIGetDestination(ItemCount destIndex0) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
ItemCount MIDIGetNumberOfDestinations() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
ItemCount MIDIGetNumberOfSources() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
MIDIEndpointRef MIDIGetSource(ItemCount sourceIndex0) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDISourceCreate(MIDIClientRef client, CFStringRef name, MIDIEndpointRef* outSrc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
MIDIEntityRef MIDIDeviceGetEntity(MIDIDeviceRef device, ItemCount entityIndex0) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
ItemCount MIDIDeviceGetNumberOfEntities(MIDIDeviceRef device) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
MIDIDeviceRef MIDIGetDevice(ItemCount deviceIndex0) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
ItemCount MIDIGetNumberOfDevices() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIClientCreate(CFStringRef name, MIDINotifyProc notifyProc, void* notifyRefCon, MIDIClientRef* outClient) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIClientDispose(MIDIClientRef client) {
    UNIMPLEMENTED();
    return StubReturn();
}
