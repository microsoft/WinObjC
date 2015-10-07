//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _AUDIOFILESTREAM_H_
#define _AUDIOFILESTREAM_H_

#import <StarboardExport.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <AudioToolbox/AudioFile.h>

typedef struct OpaqueAudioFileStreamID  *AudioFileStreamID;
typedef UInt32 AudioFileStreamPropertyID;

enum {
    kAudioFileStreamPropertyFlag_PropertyIsCached = 1,
    kAudioFileStreamPropertyFlag_CacheProperty = 2,
    kAudioFileStreamParseFlag_Discontinuity = 1,
    kAudioFileStreamSeekFlag_OffsetIsEstimated = 1
};

enum {
    kAudioFileStreamProperty_ReadyToProducePackets    = 'redy',
    kAudioFileStreamProperty_FileFormat               = 'ffmt',
    kAudioFileStreamProperty_DataFormat               = 'dfmt',
    kAudioFileStreamProperty_FormatList               = 'flst',
    kAudioFileStreamProperty_MagicCookieData          = 'mgic',
    kAudioFileStreamProperty_AudioDataByteCount       = 'bcnt',
    kAudioFileStreamProperty_AudioDataPacketCount     = 'pcnt',
    kAudioFileStreamProperty_MaximumPacketSize        = 'psze',
    kAudioFileStreamProperty_DataOffset               = 'doff',
    kAudioFileStreamProperty_ChannelLayout            = 'cmap',
    kAudioFileStreamProperty_PacketToFrame            = 'pkfr',
    kAudioFileStreamProperty_FrameToPacket            = 'frpk',
    kAudioFileStreamProperty_PacketToByte             = 'pkby',
    kAudioFileStreamProperty_ByteToPacket             = 'bypk',
    kAudioFileStreamProperty_PacketTableInfo          = 'pnfo',
    kAudioFileStreamProperty_PacketSizeUpperBound     = 'pkub',
    kAudioFileStreamProperty_AverageBytesPerPacket    = 'abpp',
    kAudioFileStreamProperty_BitRate                  = 'brat'
};

typedef void (*AudioFileStream_PropertyListenerProc) (void *inClientData, AudioFileStreamID inAudioFileStream, AudioFileStreamPropertyID inPropertyID, UInt32 *ioFlags);
typedef void (*AudioFileStream_PacketsProc) (void *inClientData, UInt32 inNumberBytes, UInt32 inNumberPackets, const void *inInputData, AudioStreamPacketDescription *inPacketDescriptions);

SB_EXPORT OSStatus AudioFileStreamClose(AudioFileStreamID inAudioFileStream);
SB_EXPORT OSStatus AudioFileStreamSeek(AudioFileStreamID inAudioFileStream, SInt64 inAbsolutePacketOffset, SInt64 *outAbsoluteByteOffset, UInt32 *ioFlags);
SB_EXPORT OSStatus AudioFileStreamOpen(void *inClientData, AudioFileStream_PropertyListenerProc inPropertyListenerProc, AudioFileStream_PacketsProc inPacketsProc, AudioFileTypeID inFileTypeHint, AudioFileStreamID *outAudioFileStream);
SB_EXPORT OSStatus AudioFileStreamParseBytes(AudioFileStreamID inAudioFileStream, UInt32 inDataByteSize, const void *inData, UInt32 inFlags);
SB_EXPORT OSStatus AudioFileStreamGetProperty(AudioFileStreamID inAudioFileStream, AudioFileStreamPropertyID inPropertyID, UInt32 *ioPropertyDataSize, void *outPropertyData);
SB_EXPORT OSStatus AudioFileStreamGetPropertyInfo(AudioFileStreamID inAudioFileStream, AudioFileStreamPropertyID inPropertyID, UInt32 *outPropertyDataSize, Boolean *outWritable);

#endif /* _AUDIOFILESTREAM_H_ */