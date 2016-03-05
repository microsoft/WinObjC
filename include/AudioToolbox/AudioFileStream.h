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
#import <CoreAudio/CoreAudioTypes.h>
#import <AudioToolbox/AudioConverter.h>
#import <AudioToolbox/AudioFile.h>

typedef CF_ENUM(UInt32, AudioFileStreamParseFlags) {
    kAudioFileStreamPropertyFlag_PropertyIsCached = 1,
    kAudioFileStreamPropertyFlag_CacheProperty = 2,
};

enum {
    kAudioFileStreamParseFlag_Discontinuity = 1,
};

typedef CF_ENUM(UInt32, AudioFileStreamSeekFlags) { kAudioFileStreamSeekFlag_OffsetIsEstimated = 1 };

enum {
    kAudioFileStreamProperty_ReadyToProducePackets = 'redy',
    kAudioFileStreamProperty_FileFormat = 'ffmt',
    kAudioFileStreamProperty_DataFormat = 'dfmt',
    kAudioFileStreamProperty_FormatList = 'flst',
    kAudioFileStreamProperty_MagicCookieData = 'mgic',
    kAudioFileStreamProperty_AudioDataByteCount = 'bcnt',
    kAudioFileStreamProperty_AudioDataPacketCount = 'pcnt',
    kAudioFileStreamProperty_MaximumPacketSize = 'psze',
    kAudioFileStreamProperty_DataOffset = 'doff',
    kAudioFileStreamProperty_ChannelLayout = 'cmap',
    kAudioFileStreamProperty_PacketToFrame = 'pkfr',
    kAudioFileStreamProperty_FrameToPacket = 'frpk',
    kAudioFileStreamProperty_PacketToByte = 'pkby',
    kAudioFileStreamProperty_ByteToPacket = 'bypk',
    kAudioFileStreamProperty_PacketTableInfo = 'pnfo',
    kAudioFileStreamProperty_PacketSizeUpperBound = 'pkub',
    kAudioFileStreamProperty_AverageBytesPerPacket = 'abpp',
    kAudioFileStreamProperty_BitRate = 'brat'
};

enum {
    kAudioFileStreamError_UnsupportedFileType = 'typ?',
    kAudioFileStreamError_UnsupportedDataFormat = 'fmt?',
    kAudioFileStreamError_UnsupportedProperty = 'pty?',
    kAudioFileStreamError_BadPropertySize = '!siz',
    kAudioFileStreamError_NotOptimized = 'optm',
    kAudioFileStreamError_InvalidPacketOffset = 'pck?',
    kAudioFileStreamError_InvalidFile = 'dta?',
    kAudioFileStreamError_ValueUnknown = 'unk?',
    kAudioFileStreamError_DataUnavailable = 'more',
    kAudioFileStreamError_IllegalOperation = 'nope',
    kAudioFileStreamError_UnspecifiedError = 'wht?',
    kAudioFileStreamError_DiscontinuityCantRecover = 'dsc!'
};

typedef UInt32 AudioFileStreamPropertyID;
typedef struct OpaqueAudioFileStreamID* AudioFileStreamID;
typedef void (*AudioFileStream_PropertyListenerProc)(void* inClientData,
                                                     AudioFileStreamID inAudioFileStream,
                                                     AudioFileStreamPropertyID inPropertyID,
                                                     UInt32* ioFlags);
typedef void (*AudioFileStream_PacketsProc)(void* inClientData,
                                            UInt32 inNumberBytes,
                                            UInt32 inNumberPackets,
                                            const void* inInputData,
                                            AudioStreamPacketDescription* inPacketDescriptions);

AUDIOTOOLBOX_EXPORT OSStatus AudioFileStreamOpen(void* inClientData,
                                                 AudioFileStream_PropertyListenerProc inPropertyListenerProc,
                                                 AudioFileStream_PacketsProc inPacketsProc,
                                                 AudioFileTypeID inFileTypeHint,
                                                 AudioFileStreamID _Nullable* outAudioFileStream) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioFileStreamParseBytes(AudioFileStreamID inAudioFileStream,
                                                       UInt32 inDataByteSize,
                                                       const void* inData,
                                                       AudioFileStreamParseFlags inFlags) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioFileStreamSeek(AudioFileStreamID inAudioFileStream,
                                                 SInt64 inPacketOffset,
                                                 SInt64* outDataByteOffset,
                                                 AudioFileStreamSeekFlags* ioFlags) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioFileStreamGetPropertyInfo(AudioFileStreamID inAudioFileStream,
                                                            AudioFileStreamPropertyID inPropertyID,
                                                            UInt32* outPropertyDataSize,
                                                            Boolean* outWritable) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioFileStreamGetProperty(AudioFileStreamID inAudioFileStream,
                                                        AudioFileStreamPropertyID inPropertyID,
                                                        UInt32* ioPropertyDataSize,
                                                        void* outPropertyData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioFileStreamSetProperty(AudioFileStreamID inAudioFileStream,
                                                        AudioFileStreamPropertyID inPropertyID,
                                                        UInt32 inPropertyDataSize,
                                                        const void* inPropertyData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioFileStreamClose(AudioFileStreamID inAudioFileStream) STUB_METHOD;