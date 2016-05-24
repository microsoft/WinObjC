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
#pragma once

#import <CoreMIDI/CoreMIDIExport.h>
#import <CoreFoundation/CFPropertyList.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFData.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFBase.h>

typedef UInt32 MIDIObjectRef;
typedef SInt32 MIDINotificationMessageID;
typedef SInt32 MIDIObjectType;
typedef UInt64 MIDITimeStamp;
typedef SInt32 MIDIUniqueID;
typedef MIDIObjectRef MIDIDeviceRef;
typedef MIDIObjectRef MIDIClientRef;
typedef MIDIObjectRef MIDIEndpointRef;
typedef MIDIObjectRef MIDIEntityRef;
typedef MIDIObjectRef MIDIPortRef;

struct MIDINotification {
    MIDINotificationMessageID messageID;
    UInt32 messageSize; // additional data may follow, depending on messageID
};

typedef struct MIDINotification MIDINotification;

struct MIDIObjectAddRemoveNotification {
    MIDINotificationMessageID messageID;
    UInt32 messageSize;
    MIDIObjectRef parent;
    MIDIObjectType parentType;
    MIDIObjectRef child;
    MIDIObjectType childType;
};

struct MIDIObjectPropertyChangeNotification {
    MIDINotificationMessageID messageID;
    UInt32 messageSize;
    MIDIObjectRef object;
    MIDIObjectType objectType;
    CFStringRef propertyName;
};

struct MIDIIOErrorNotification {
    MIDINotificationMessageID messageID;
    UInt32 messageSize;
    MIDIDeviceRef driverDevice;
    OSStatus errorCode;
};

typedef struct MIDIPacket {
    MIDITimeStamp timeStamp;
    UInt16 length;
    Byte data[256];
} MIDIPacket;

typedef struct MIDIPacketList {
    UInt32 numPackets;
    MIDIPacket packet[1];
} MIDIPacketList;

struct MIDISysexSendRequest; // Forward declaring.
typedef void (*MIDICompletionProc)(struct MIDISysexSendRequest* request);
typedef struct MIDISysexSendRequest {
    MIDIEndpointRef destination;
    const Byte* data;
    UInt32 bytesToSend;
    Boolean complete;
    Byte reserved[3];
    MIDICompletionProc completionProc;
    void* completionRefCon;
} MIDISysexSendRequest;

typedef struct MIDISysexSendRequest MIDISysexSendRequest;
typedef void (*MIDINotifyProc)(const MIDINotification* message, void* refCon);
typedef void (*MIDIReadProc)(const MIDIPacketList* pktlist, void* readProcRefCon, void* srcConnRefCon);
typedef struct MIDIObjectAddRemoveNotification MIDIObjectAddRemoveNotification;
typedef struct MIDIObjectPropertyChangeNotification MIDIObjectPropertyChangeNotification;
typedef struct MIDIIOErrorNotification MIDIIOErrorNotification;

enum {
    kMIDIObjectType_Other = -1,
    kMIDIObjectType_Device = 0,
    kMIDIObjectType_Entity = 1,
    kMIDIObjectType_Source = 2,
    kMIDIObjectType_Destination = 3,
    kMIDIObjectType_ExternalMask = 0x10,
    kMIDIObjectType_ExternalDevice = kMIDIObjectType_ExternalMask | kMIDIObjectType_Device,
    kMIDIObjectType_ExternalEntity = kMIDIObjectType_ExternalMask | kMIDIObjectType_Entity,
    kMIDIObjectType_ExternalSource = kMIDIObjectType_ExternalMask | kMIDIObjectType_Source,
    kMIDIObjectType_ExternalDestination = kMIDIObjectType_ExternalMask | kMIDIObjectType_Destination
};

enum {
    kMIDIMsgSetupChanged = 1,
    kMIDIMsgObjectAdded = 2,
    kMIDIMsgObjectRemoved = 3,
    kMIDIMsgPropertyChanged = 4,
    kMIDIMsgThruConnectionsChanged = 5,
    kMIDIMsgSerialPortOwnerChanged = 6,
    kMIDIMsgIOError = 7
};

typedef UInt64 ByteCount;
typedef UInt64 ItemCount;

COREMIDI_EXPORT OSStatus
MIDIInputPortCreate(MIDIClientRef client, CFStringRef portName, MIDIReadProc readProc, void* refCon, MIDIPortRef* outPort) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIOutputPortCreate(MIDIClientRef client, CFStringRef portName, MIDIPortRef* outPort) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIPortConnectSource(MIDIPortRef port, MIDIEndpointRef source, void* connRefCon) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIPortDisconnectSource(MIDIPortRef port, MIDIEndpointRef source) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIPortDispose(MIDIPortRef port) STUB_METHOD;
COREMIDI_EXPORT MIDIPacket* MIDIPacketListAdd(
    MIDIPacketList* pktlist, ByteCount listSize, MIDIPacket* curPacket, MIDITimeStamp time, ByteCount nData, const Byte* data) STUB_METHOD;
COREMIDI_EXPORT MIDIPacket* MIDIPacketListInit(MIDIPacketList* pktlist) STUB_METHOD;
COREMIDI_EXPORT MIDIPacket* MIDIPacketNext(const MIDIPacket* pkt) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectFindByUniqueID(MIDIUniqueID inUniqueID,
                                                  MIDIObjectRef* outObject,
                                                  MIDIObjectType* outObjectType) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectGetDataProperty(MIDIObjectRef obj, CFStringRef propertyID, CFDataRef _Nullable* outData) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectGetDictionaryProperty(MIDIObjectRef obj,
                                                         CFStringRef propertyID,
                                                         CFDictionaryRef _Nullable* outDict) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectGetIntegerProperty(MIDIObjectRef obj, CFStringRef propertyID, SInt32* outValue) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectGetProperties(MIDIObjectRef obj, CFPropertyListRef _Nullable* outProperties, Boolean deep) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectGetStringProperty(MIDIObjectRef obj, CFStringRef propertyID, CFStringRef _Nullable* str) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectRemoveProperty(MIDIObjectRef obj, CFStringRef propertyID) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectSetDataProperty(MIDIObjectRef obj, CFStringRef propertyID, CFDataRef data) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectSetDictionaryProperty(MIDIObjectRef obj, CFStringRef propertyID, CFDictionaryRef dict) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectSetIntegerProperty(MIDIObjectRef obj, CFStringRef propertyID, SInt32 value) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIObjectSetStringProperty(MIDIObjectRef obj, CFStringRef propertyID, CFStringRef str) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIFlushOutput(MIDIEndpointRef dest) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIReceived(MIDIEndpointRef src, const MIDIPacketList* pktlist) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIRestart() STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDISend(MIDIPortRef port, MIDIEndpointRef dest, const MIDIPacketList* pktlist) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDISendSysex(MIDISysexSendRequest* request) STUB_METHOD;
COREMIDI_EXPORT MIDIDeviceRef MIDIGetExternalDevice(ItemCount deviceIndex0) STUB_METHOD;
COREMIDI_EXPORT ItemCount MIDIGetNumberOfExternalDevices() STUB_METHOD;
COREMIDI_EXPORT MIDIEndpointRef MIDIEntityGetDestination(MIDIEntityRef entity, ItemCount destIndex0) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIEntityGetDevice(MIDIEntityRef inEntity, MIDIDeviceRef* outDevice) STUB_METHOD;
COREMIDI_EXPORT ItemCount MIDIEntityGetNumberOfDestinations(MIDIEntityRef entity) STUB_METHOD;
COREMIDI_EXPORT ItemCount MIDIEntityGetNumberOfSources(MIDIEntityRef entity) STUB_METHOD;
COREMIDI_EXPORT MIDIEndpointRef MIDIEntityGetSource(MIDIEntityRef entity, ItemCount sourceIndex0) STUB_METHOD;
COREMIDI_EXPORT OSStatus
MIDIDestinationCreate(MIDIClientRef client, CFStringRef name, MIDIReadProc readProc, void* refCon, MIDIEndpointRef* outDest) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIEndpointDispose(MIDIEndpointRef endpt) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIEndpointGetEntity(MIDIEndpointRef inEndpoint, MIDIEntityRef* outEntity) STUB_METHOD;
COREMIDI_EXPORT MIDIEndpointRef MIDIGetDestination(ItemCount destIndex0) STUB_METHOD;
COREMIDI_EXPORT ItemCount MIDIGetNumberOfDestinations() STUB_METHOD;
COREMIDI_EXPORT ItemCount MIDIGetNumberOfSources() STUB_METHOD;
COREMIDI_EXPORT MIDIEndpointRef MIDIGetSource(ItemCount sourceIndex0) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDISourceCreate(MIDIClientRef client, CFStringRef name, MIDIEndpointRef* outSrc) STUB_METHOD;
COREMIDI_EXPORT MIDIEntityRef MIDIDeviceGetEntity(MIDIDeviceRef device, ItemCount entityIndex0) STUB_METHOD;
COREMIDI_EXPORT ItemCount MIDIDeviceGetNumberOfEntities(MIDIDeviceRef device) STUB_METHOD;
COREMIDI_EXPORT MIDIDeviceRef MIDIGetDevice(ItemCount deviceIndex0) STUB_METHOD;
COREMIDI_EXPORT ItemCount MIDIGetNumberOfDevices() STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIClientCreate(CFStringRef name, MIDINotifyProc notifyProc, void* notifyRefCon, MIDIClientRef* outClient)
    STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIClientDispose(MIDIClientRef client) STUB_METHOD;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyAdvanceScheduleTimeMuSec;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyCanRoute;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyConnectionUniqueID;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyDeviceID;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyDisplayName;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyDriverDeviceEditorApp;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyDriverOwner;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyDriverVersion;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyImage;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyIsBroadcast;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyIsDrumMachine;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyIsEffectUnit;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyIsEmbeddedEntity;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyIsMixer;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyIsSampler;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyManufacturer;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyMaxReceiveChannels;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyMaxSysExSpeed;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyMaxTransmitChannels;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyModel;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyName;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyNameConfiguration;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyOffline;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyPanDisruptsStereo;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyPrivate;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyReceiveChannels;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyReceivesBankSelectLSB;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyReceivesBankSelectMSB;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyReceivesClock;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyReceivesMTC;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyReceivesNotes;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyReceivesProgramChanges;
COREMIDI_EXPORT const CFStringRef kMIDIPropertySingleRealtimeEntity;
COREMIDI_EXPORT const CFStringRef kMIDIPropertySupportsGeneralMIDI;
COREMIDI_EXPORT const CFStringRef kMIDIPropertySupportsMMC;
COREMIDI_EXPORT const CFStringRef kMIDIPropertySupportsShowControl;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyTransmitChannels;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyTransmitsBankSelectLSB;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyTransmitsBankSelectMSB;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyTransmitsClock;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyTransmitsMTC;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyTransmitsNotes;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyTransmitsProgramChanges;
COREMIDI_EXPORT const CFStringRef kMIDIPropertyUniqueID;

enum {
    kMIDIInvalidClient = -10830,
    kMIDIInvalidPort = -10831,
    kMIDIWrongEndpointType = -10832,
    kMIDINoConnection = -10833,
    kMIDIUnknownEndpoint = -10834,
    kMIDIUnknownProperty = -10835,
    kMIDIWrongPropertyType = -10836,
    kMIDINoCurrentSetup = -10837,
    kMIDIMessageSendErr = -10838,
    kMIDIServerStartErr = -10839,
    kMIDISetupFormatErr = -10840,
    kMIDIWrongThread = -10841,
    kMIDIObjectNotFound = -10842,
    kMIDIIDNotUnique = -10843
};

enum { kMIDIInvalidUniqueID = 0 };
