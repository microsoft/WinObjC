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
#import <CoreMIDI/MIDIServices.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFData.h>

#if __LP64__
typedef MIDIObjectRef MIDIThruConnectionRef;
#else
typedef struct OpaqueMIDIThruConnection* MIDIThruConnectionRef;
#endif

typedef CF_ENUM(UInt32, MIDITransformControlType) {
    kMIDIControlType_7Bit = 0,
    kMIDIControlType_14Bit = 1,
    kMIDIControlType_7BitRPN = 2,
    kMIDIControlType_14BitRPN = 3,
    kMIDIControlType_7BitNRPN = 4,
    kMIDIControlType_14BitNRPN = 5
};

enum {
    kMIDITransform_None = 0,
    kMIDITransform_FilterOut = 1,
    kMIDITransform_MapControl = 2,
    kMIDITransform_Add = 8,
    kMIDITransform_Scale = 9,
    kMIDITransform_MinValue = 10,
    kMIDITransform_MaxValue = 11,
    kMIDITransform_MapValue = 12
};

enum { kMIDIThruConnection_MaxEndpoints = 8 };

typedef UInt16 MIDITransformType;

struct MIDITransform {
    MIDITransformType transform;
    SInt16 param;
};
typedef struct MIDITransform MIDITransform;

typedef struct MIDIControlTransform {
    MIDITransformControlType controlType;
    MIDITransformControlType remappedControlType;
    UInt16 controlNumber;
    MIDITransformType transform;
    SInt16 param;
} MIDIControlTransform;
typedef struct MIDIControlTransform MIDIControlTransform;

struct MIDIThruConnectionEndpoint {
    MIDIEndpointRef endpointRef;
    MIDIUniqueID uniqueID;
};
typedef struct MIDIThruConnectionEndpoint MIDIThruConnectionEndpoint;

struct MIDIThruConnectionParams {
    UInt32 version;
    UInt32 numSources;
    MIDIThruConnectionEndpoint sources[kMIDIThruConnection_MaxEndpoints];
    UInt32 numDestinations;
    MIDIThruConnectionEndpoint destinations[kMIDIThruConnection_MaxEndpoints];
    UInt8 channelMap[16];
    UInt8 lowVelocity, highVelocity;
    UInt8 lowNote, highNote;
    MIDITransform noteNumber;
    MIDITransform velocity;
    MIDITransform keyPressure;
    MIDITransform channelPressure;
    MIDITransform programChange;
    MIDITransform pitchBend;
    UInt8 filterOutSysEx;
    UInt8 filterOutMTC;
    UInt8 filterOutBeatClock;
    UInt8 filterOutTuneRequest;
    UInt8 reserved2[3];
    UInt8 filterOutAllControls;
    UInt16 numControlTransforms;
    UInt16 numMaps;
    UInt16 reserved3[4]; // remainder of structure is variable -length: MIDIControlTransform controls[]; MIDIValueMap maps[];
};
typedef struct MIDIThruConnectionParams MIDIThruConnectionParams;

struct MIDIValueMap {
    UInt8 value[128];
};
typedef struct MIDIValueMap MIDIValueMap;

#define MIDIThruConnectionParamsSize                                                                           \
    (ptr) \ (sizeof(MIDIThruConnectionParams) + (ptr)->numControlTransforms * sizeof(MIDIControlTransform) \ + \
             (ptr)->numMaps * sizeof(MIDIValueMap))

COREMIDI_EXPORT OSStatus MIDIThruConnectionCreate(CFStringRef inPersistentOwnerID,
                                                  CFDataRef inConnectionParams,
                                                  MIDIThruConnectionRef* outConnection) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIThruConnectionDispose(MIDIThruConnectionRef connection) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIThruConnectionFind(CFStringRef inPersistentOwnerID, CFDataRef _Nonnull* outConnectionList) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIThruConnectionGetParams(MIDIThruConnectionRef connection, CFDataRef _Nonnull* outConnectionParams) STUB_METHOD;
COREMIDI_EXPORT void MIDIThruConnectionParamsInitialize(MIDIThruConnectionParams* inConnectionParams) STUB_METHOD;
COREMIDI_EXPORT OSStatus MIDIThruConnectionSetParams(MIDIThruConnectionRef connection, CFDataRef inConnectionParams) STUB_METHOD;
