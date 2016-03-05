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

#import <AudioToolbox/MusicSequence.h>
#import <StubReturn.h>

/**
 @Status Stub
 @Notes
*/
OSStatus NewMusicSequence(MusicSequence _Nullable* outSequence) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus DisposeMusicSequence(MusicSequence inSequence) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceSetSequenceType(MusicSequence inSequence, MusicSequenceType inType) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceGetSequenceType(MusicSequence inSequence, MusicSequenceType* outType) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
SInt16 MusicSequenceSetSMPTEResolution(SignedByte fps, Byte ticks) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void MusicSequenceGetSMPTEResolution(SInt16 inRes, SignedByte* fps, Byte* ticks) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceSetUserCallback(MusicSequence inSequence, MusicSequenceUserCallback inCallback, void* inClientData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef MusicSequenceGetInfoDictionary(MusicSequence inSequence) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceNewTrack(MusicSequence inSequence, MusicTrack _Nullable* outTrack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceDisposeTrack(MusicSequence inSequence, MusicTrack inTrack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceGetTrackCount(MusicSequence inSequence, UInt32* outNumberOfTracks) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceGetIndTrack(MusicSequence inSequence, UInt32 inTrackIndex, MusicTrack _Nullable* outTrack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceGetTrackIndex(MusicSequence inSequence, MusicTrack inTrack, UInt32* outTrackIndex) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceGetTempoTrack(MusicSequence inSequence, MusicTrack _Nullable* outTrack) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceSetAUGraph(MusicSequence inSequence, AUGraph inGraph) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceGetAUGraph(MusicSequence inSequence, AUGraph _Nullable* outGraph) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceSetMIDIEndpoint(MusicSequence inSequence, MIDIEndpointRef inEndpoint) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceGetSecondsForBeats(MusicSequence inSequence, MusicTimeStamp inBeats, Float64* outSeconds) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceGetBeatsForSeconds(MusicSequence inSequence, Float64 inSeconds, MusicTimeStamp* outBeats) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceBeatsToBarBeatTime(MusicSequence inSequence,
                                         MusicTimeStamp inBeats,
                                         UInt32 inSubbeatDivisor,
                                         CABarBeatTime* outBarBeatTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceBarBeatTimeToBeats(MusicSequence inSequence, const CABarBeatTime* inBarBeatTime, MusicTimeStamp* outBeats) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceReverse(MusicSequence inSequence) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceFileLoad(MusicSequence inSequence,
                               CFURLRef inFileRef,
                               MusicSequenceFileTypeID inFileTypeHint,
                               MusicSequenceLoadFlags inFlags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceFileLoadData(MusicSequence inSequence,
                                   CFDataRef inData,
                                   MusicSequenceFileTypeID inFileTypeHint,
                                   MusicSequenceLoadFlags inFlags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceFileCreate(
    MusicSequence inSequence, CFURLRef inFileRef, MusicSequenceFileTypeID inFileType, MusicSequenceFileFlags inFlags, SInt16 inResolution) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MusicSequenceFileCreateData(MusicSequence inSequence,
                                     MusicSequenceFileTypeID inFileType,
                                     MusicSequenceFileFlags inFlags,
                                     SInt16 inResolution,
                                     CFDataRef _Nullable* outData) {
    UNIMPLEMENTED();
    return StubReturn();
}