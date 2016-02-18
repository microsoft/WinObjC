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

#import <AudioToolbox/AudioToolboxExport.h>
#import <AudioToolbox/AudioConverter.h>
#import <AudioToolbox/AudioUnitProcessingGraph.h>
#import <AudioToolbox/MusicDevice.h>
#import <CoreMIDI/MIDIServices.h>
#import <AudioToolbox/MusicCommon.h>
#import <AudioUnit/AudioUnitComponent.h>
#import <CoreFoundation/CFPropertyList.h>

enum {
    kSequenceTrackProperty_LoopInfo = 0,
    kSequenceTrackProperty_OffsetTime = 1,
    kSequenceTrackProperty_MuteStatus = 2,
    kSequenceTrackProperty_SoloStatus = 3,
    kSequenceTrackProperty_AutomatedParameters = 4,
    kSequenceTrackProperty_TrackLength = 5,
    kSequenceTrackProperty_TimeResolution = 6
};

typedef Float64 MusicTimeStamp;

typedef struct MusicTrackLoopInfo {
    MusicTimeStamp loopDuration;
    SInt32 numberOfLoops;
} MusicTrackLoopInfo;

typedef struct MIDINoteMessage {
    UInt8 channel;
    UInt8 note;
    UInt8 velocity;
    UInt8 releaseVelocity;
    Float32 duration;
} MIDINoteMessage;

typedef struct MIDIChannelMessage {
    UInt8 status;
    UInt8 data1;
    UInt8 data2;
    UInt8 reserved;
} MIDIChannelMessage;

typedef struct MIDIRawData {
    UInt32 length;
    UInt8 data[1];
} MIDIRawData;

typedef struct MIDIMetaEvent {
    UInt8 metaEventType;
    UInt8 unused1;
    UInt8 unused2;
    UInt8 unused3;
    UInt32 dataLength;
    UInt8 data[1];
} MIDIMetaEvent;

typedef struct MusicEventUserData {
    UInt32 length;
    UInt8 data[1];
} MusicEventUserData;

typedef struct ExtendedNoteOnEvent {
    MusicDeviceInstrumentID instrumentID;
    MusicDeviceGroupID groupID;
    Float32 duration;
    MusicDeviceNoteParams extendedParams;
} ExtendedNoteOnEvent;

typedef struct ParameterEvent {
    AudioUnitParameterID parameterID;
    AudioUnitScope scope;
    AudioUnitElement element;
    AudioUnitParameterValue value;
} ParameterEvent;

typedef struct ExtendedTempoEvent { Float64 bpm; } ExtendedTempoEvent;

typedef struct AUPresetEvent {
    AudioUnitScope scope;
    AudioUnitElement element;
    CFPropertyListRef preset;
} AUPresetEvent;

AUDIOTOOLBOX_EXPORT OSStatus MusicTrackGetSequence(MusicTrack inTrack, MusicSequence _Nullable* outSequence) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackSetDestNode(MusicTrack inTrack, AUNode inNode) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackSetDestMIDIEndpoint(MusicTrack inTrack, MIDIEndpointRef inEndpoint) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackGetDestNode(MusicTrack inTrack, AUNode* outNode) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackGetDestMIDIEndpoint(MusicTrack inTrack, MIDIEndpointRef* outEndpoint) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackSetProperty(MusicTrack inTrack, UInt32 inPropertyID, void* inData, UInt32 inLength) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackGetProperty(MusicTrack inTrack, UInt32 inPropertyID, void* outData, UInt32* ioLength) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackNewMIDINoteEvent(MusicTrack inTrack,
                                                        MusicTimeStamp inTimeStamp,
                                                        const MIDINoteMessage* inMessage) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackNewMIDIChannelEvent(MusicTrack inTrack,
                                                           MusicTimeStamp inTimeStamp,
                                                           const MIDIChannelMessage* inMessage) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackNewMIDIRawDataEvent(MusicTrack inTrack,
                                                           MusicTimeStamp inTimeStamp,
                                                           const MIDIRawData* inRawData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackNewExtendedNoteEvent(MusicTrack inTrack,
                                                            MusicTimeStamp inTimeStamp,
                                                            const ExtendedNoteOnEvent* inInfo) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackNewParameterEvent(MusicTrack inTrack,
                                                         MusicTimeStamp inTimeStamp,
                                                         const ParameterEvent* inInfo) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackNewExtendedTempoEvent(MusicTrack inTrack, MusicTimeStamp inTimeStamp, Float64 inBPM) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackNewMetaEvent(MusicTrack inTrack,
                                                    MusicTimeStamp inTimeStamp,
                                                    const MIDIMetaEvent* inMetaEvent) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackNewUserEvent(MusicTrack inTrack,
                                                    MusicTimeStamp inTimeStamp,
                                                    const MusicEventUserData* inUserData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackNewAUPresetEvent(MusicTrack inTrack,
                                                        MusicTimeStamp inTimeStamp,
                                                        const AUPresetEvent* inPresetEvent) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackMoveEvents(MusicTrack inTrack,
                                                  MusicTimeStamp inStartTime,
                                                  MusicTimeStamp inEndTime,
                                                  MusicTimeStamp inMoveTime) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackClear(MusicTrack inTrack, MusicTimeStamp inStartTime, MusicTimeStamp inEndTime) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackCut(MusicTrack inTrack, MusicTimeStamp inStartTime, MusicTimeStamp inEndTime) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackCopyInsert(MusicTrack inSourceTrack,
                                                  MusicTimeStamp inSourceStartTime,
                                                  MusicTimeStamp inSourceEndTime,
                                                  MusicTrack inDestTrack,
                                                  MusicTimeStamp inDestInsertTime) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicTrackMerge(MusicTrack inSourceTrack,
                                             MusicTimeStamp inSourceStartTime,
                                             MusicTimeStamp inSourceEndTime,
                                             MusicTrack inDestTrack,
                                             MusicTimeStamp inDestInsertTime) STUB_METHOD;