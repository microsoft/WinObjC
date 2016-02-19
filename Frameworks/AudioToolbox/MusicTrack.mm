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

#import <AudioToolbox/MusicTrack.h>
#import <StubReturn.h>

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackGetSequence(MusicTrack inTrack, MusicSequence _Nullable* outSequence) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackSetDestNode(MusicTrack inTrack, AUNode inNode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackSetDestMIDIEndpoint(MusicTrack inTrack, MIDIEndpointRef inEndpoint) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackGetDestNode(MusicTrack inTrack, AUNode* outNode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackGetDestMIDIEndpoint(MusicTrack inTrack, MIDIEndpointRef* outEndpoint) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackSetProperty(MusicTrack inTrack, UInt32 inPropertyID, void* inData, UInt32 inLength) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackGetProperty(MusicTrack inTrack, UInt32 inPropertyID, void* outData, UInt32* ioLength) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackNewMIDINoteEvent(MusicTrack inTrack, MusicTimeStamp inTimeStamp, const MIDINoteMessage* inMessage) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackNewMIDIChannelEvent(MusicTrack inTrack, MusicTimeStamp inTimeStamp, const MIDIChannelMessage* inMessage) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackNewMIDIRawDataEvent(MusicTrack inTrack, MusicTimeStamp inTimeStamp, const MIDIRawData* inRawData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackNewExtendedNoteEvent(MusicTrack inTrack, MusicTimeStamp inTimeStamp, const ExtendedNoteOnEvent* inInfo) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackNewParameterEvent(MusicTrack inTrack, MusicTimeStamp inTimeStamp, const ParameterEvent* inInfo) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackNewExtendedTempoEvent(MusicTrack inTrack, MusicTimeStamp inTimeStamp, Float64 inBPM) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackNewMetaEvent(MusicTrack inTrack, MusicTimeStamp inTimeStamp, const MIDIMetaEvent* inMetaEvent) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackNewUserEvent(MusicTrack inTrack, MusicTimeStamp inTimeStamp, const MusicEventUserData* inUserData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackNewAUPresetEvent(MusicTrack inTrack, MusicTimeStamp inTimeStamp, const AUPresetEvent* inPresetEvent) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackMoveEvents(MusicTrack inTrack, MusicTimeStamp inStartTime, MusicTimeStamp inEndTime, MusicTimeStamp inMoveTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackClear(MusicTrack inTrack, MusicTimeStamp inStartTime, MusicTimeStamp inEndTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackCut(MusicTrack inTrack, MusicTimeStamp inStartTime, MusicTimeStamp inEndTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackCopyInsert(MusicTrack inSourceTrack,
                              MusicTimeStamp inSourceStartTime,
                              MusicTimeStamp inSourceEndTime,
                              MusicTrack inDestTrack,
                              MusicTimeStamp inDestInsertTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicTrackMerge(MusicTrack inSourceTrack,
                         MusicTimeStamp inSourceStartTime,
                         MusicTimeStamp inSourceEndTime,
                         MusicTrack inDestTrack,
                         MusicTimeStamp inDestInsertTime) {
    UNIMPLEMENTED();
    return StubReturn();
}