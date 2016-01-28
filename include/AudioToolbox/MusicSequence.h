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
#import <CoreFoundation/CFDictionary.h>
#import <AudioToolbox/MusicDevice.h>
#import <AudioToolbox/MusicCommon.h>
#import <AudioToolbox/MusicTrack.h>
#import <AudioToolbox/AudioUnitProcessingGraph.h>
#import <CoreAudio/CoreAudioClock.h>
#import <CoreMIDI/MIDIServices.h>
#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFURL.h>
#import <CoreFoundation/CFData.h>

typedef UInt32 MusicSequenceLoadFlags;
typedef UInt32 MusicSequenceType;
typedef UInt32 MusicSequenceFileTypeID;
typedef UInt32 MusicSequenceFileFlags;
typedef void (*MusicSequenceUserCallback)(void* inClientData,
                                          MusicSequence inSequence,
                                          MusicTrack inTrack,
                                          MusicTimeStamp inEventTime,
                                          const MusicEventUserData* inEventData,
                                          MusicTimeStamp inStartSliceBeat,
                                          MusicTimeStamp inEndSliceBeat);

enum { kMusicSequenceLoadSMF_ChannelsToTracks = (1 << 0) };
enum { kMusicSequenceType_Beats = 'beat', kMusicSequenceType_Seconds = 'secs', kMusicSequenceType_Samples = 'samp' };
enum { kMusicSequenceFile_MIDIType = 'midi', kMusicSequenceFile_iMelodyType = 'imel' };
enum { kMusicSequenceFileFlags_EraseFile = 1 };

AUDIOTOOLBOX_EXPORT OSStatus NewMusicSequence(MusicSequence _Nullable* outSequence) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus DisposeMusicSequence(MusicSequence inSequence) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceSetSequenceType(MusicSequence inSequence, MusicSequenceType inType) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceGetSequenceType(MusicSequence inSequence, MusicSequenceType* outType) STUB_METHOD;
AUDIOTOOLBOX_EXPORT SInt16 MusicSequenceSetSMPTEResolution(SignedByte fps, Byte ticks) STUB_METHOD;
AUDIOTOOLBOX_EXPORT void MusicSequenceGetSMPTEResolution(SInt16 inRes, SignedByte* fps, Byte* ticks) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceSetUserCallback(MusicSequence inSequence,
                                                          MusicSequenceUserCallback inCallback,
                                                          void* inClientData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT CFDictionaryRef MusicSequenceGetInfoDictionary(MusicSequence inSequence) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceNewTrack(MusicSequence inSequence, MusicTrack _Nullable* outTrack) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceDisposeTrack(MusicSequence inSequence, MusicTrack inTrack) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceGetTrackCount(MusicSequence inSequence, UInt32* outNumberOfTracks) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceGetIndTrack(MusicSequence inSequence,
                                                      UInt32 inTrackIndex,
                                                      MusicTrack _Nullable* outTrack) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceGetTrackIndex(MusicSequence inSequence, MusicTrack inTrack, UInt32* outTrackIndex) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceGetTempoTrack(MusicSequence inSequence, MusicTrack _Nullable* outTrack) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceSetAUGraph(MusicSequence inSequence, AUGraph inGraph) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceGetAUGraph(MusicSequence inSequence, AUGraph _Nullable* outGraph) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceSetMIDIEndpoint(MusicSequence inSequence, MIDIEndpointRef inEndpoint) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceGetSecondsForBeats(MusicSequence inSequence,
                                                             MusicTimeStamp inBeats,
                                                             Float64* outSeconds) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceGetBeatsForSeconds(MusicSequence inSequence,
                                                             Float64 inSeconds,
                                                             MusicTimeStamp* outBeats) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceBeatsToBarBeatTime(MusicSequence inSequence,
                                                             MusicTimeStamp inBeats,
                                                             UInt32 inSubbeatDivisor,
                                                             CABarBeatTime* outBarBeatTime) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceBarBeatTimeToBeats(MusicSequence inSequence,
                                                             const CABarBeatTime* inBarBeatTime,
                                                             MusicTimeStamp* outBeats) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceReverse(MusicSequence inSequence) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceFileLoad(MusicSequence inSequence,
                                                   CFURLRef inFileRef,
                                                   MusicSequenceFileTypeID inFileTypeHint,
                                                   MusicSequenceLoadFlags inFlags) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceFileLoadData(MusicSequence inSequence,
                                                       CFDataRef inData,
                                                       MusicSequenceFileTypeID inFileTypeHint,
                                                       MusicSequenceLoadFlags inFlags) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceFileCreate(MusicSequence inSequence,
                                                     CFURLRef inFileRef,
                                                     MusicSequenceFileTypeID inFileType,
                                                     MusicSequenceFileFlags inFlags,
                                                     SInt16 inResolution) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus MusicSequenceFileCreateData(MusicSequence inSequence,
                                                         MusicSequenceFileTypeID inFileType,
                                                         MusicSequenceFileFlags inFlags,
                                                         SInt16 inResolution,
                                                         CFDataRef _Nullable* outData) STUB_METHOD;
