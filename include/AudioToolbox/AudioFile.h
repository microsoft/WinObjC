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

#ifndef _AUDIOFILE_H_
#define _AUDIOFILE_H_

#import <CoreAudio/CoreAudioTypes.h>
#import <CoreFoundation/CFURL.h>
#import <StarboardExport.h>
#import <AudioToolbox/AudioToolboxExport.h>

struct AudioFile;
typedef struct AudioFile* AudioFileID;
typedef uint32_t AudioFilePropertyID;
typedef uint32_t AudioFileTypeID;

typedef OSStatus (*AudioFile_ReadProc)(void* clientData, int64_t position, uint32_t count, void* buffer, uint32_t* outCount);
typedef OSStatus (*AudioFile_WriteProc)(void* clientData, int64_t position, uint32_t count, const void* buffer, uint32_t* outCount);
typedef int64_t (*AudioFile_GetSizeProc)(void* clientData);
typedef OSStatus (*AudioFile_SetSizeProc)(void* clientData, int64_t size);

enum {
    kAudioFileReadPermission = 1,
    kAudioFileWritePermission = 2,
    kAudioFileReadWritePermission = 3,
};

enum {
    kAudioFilePropertyFileFormat = 'ffmt',
    kAudioFilePropertyDataFormat = 'dfmt',
    kAudioFilePropertyIsOptimized = 'optm',
    kAudioFilePropertyMagicCookieData = 'mgic',
    kAudioFilePropertyAudioDataByteCount = 'bcnt',
    kAudioFilePropertyAudioDataPacketCount = 'pcnt',
    kAudioFilePropertyMaximumPacketSize = 'psze',
    kAudioFilePropertyDataOffset = 'doff',
    kAudioFilePropertyChannelLayout = 'cmap',
    kAudioFilePropertyDeferSizeUpdates = 'dszu',
    kAudioFilePropertyDataFormatName = 'fnme',
    kAudioFilePropertyMarkerList = 'mkls',
    kAudioFilePropertyRegionList = 'rgls',
    kAudioFilePropertyPacketToFrame = 'pkfr',
    kAudioFilePropertyFrameToPacket = 'frpk',
    kAudioFilePropertyPacketToByte = 'pkby',
    kAudioFilePropertyByteToPacket = 'bypk',
    kAudioFilePropertyChunkIDs = 'chid',
    kAudioFilePropertyInfoDictionary = 'info',
    kAudioFilePropertyPacketTableInfo = 'pnfo',
    kAudioFilePropertyFormatList = 'flst',
    kAudioFilePropertyPacketSizeUpperBound = 'pkub',
    kAudioFilePropertyReserveDuration = 'rsrv',
    kAudioFilePropertyEstimatedDuration = 'edur',
    kAudioFilePropertyBitRate = 'brat',
    kAudioFilePropertyID3Tag = 'id3t'
};

enum {
    kAudioFileAIFFType = 'AIFF',
    kAudioFileAIFCType = 'AIFC',
    kAudioFileWAVEType = 'WAVE',
    kAudioFileSoundDesigner2Type = 'Sd2f',
    kAudioFileNextType = 'NeXT',
    kAudioFileMP3Type = 'MPG3',
    kAudioFileMP2Type = 'MPG2',
    kAudioFileMP1Type = 'MPG1',
    kAudioFileAC3Type = 'ac-3',
    kAudioFileAAC_ADTSType = 'adts',
    kAudioFileMPEG4Type = 'mp4f',
    kAudioFileM4AType = 'm4af',
    kAudioFileCAFType = 'caff',
    kAudioFile3GPType = '3gpp',
    kAudioFile3GP2Type = '3gp2',
    kAudioFileAMRType = 'amrf'
};
typedef uint32_t AudioFileTypeID;

AUDIOTOOLBOX_EXPORT OSStatus
AudioFileReadBytes(AudioFileID inFile, Boolean useCache, SInt64 startingByte, UInt32* numBytes, void* outBuffer);
AUDIOTOOLBOX_EXPORT OSStatus AudioFileGetProperty(AudioFileID inFile, AudioFilePropertyID propertyID, UInt32* dataSize, void* propertyData);
AUDIOTOOLBOX_EXPORT OSStatus AudioFileClose(AudioFileID inFile);
AUDIOTOOLBOX_EXPORT OSStatus AudioFileOpenURL(CFURLRef fileRef, SInt8 permissions, AudioFileTypeID hint, AudioFileID* outFile);

#endif // _AUDIOFILE_H_
