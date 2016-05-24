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

#import <math.h>
#import <time.h>
#import <pthread.h>
#import <algorithm>

#import "Starboard.h"
#import "Platform/EbrPlatform.h"
#import "Etc.h"
#include "CAFDecoder.h"
#include "LoggingNative.h"

static const wchar_t* TAG = L"AudioFile";

#import "stb_vorbis.h"
#import <AudioToolbox/AudioFile.h>
#import <AudioToolbox/AudioFileTypes.h>
#import <AudioToolbox/ExtendedAudioFile.h>
#import <StubReturn.h>

struct OpaqueAudioFileID {
protected:
    AudioStreamBasicDescription clientDataFormat;
    bool clientDataFormatSet;

    AudioStreamBasicDescription fileFormat;

public:
    OpaqueAudioFileID() : clientDataFormatSet(false) {
        memset(&fileFormat, 0, sizeof(fileFormat));
    }

    virtual int read(u32* outFrameCount, AudioBufferList* buffers) {
        return 0;
    }
    virtual int readBytes(i64 start, u32* numBytes, void* buffer) {
        return 0;
    }

    virtual u32 getProperty(u32 propID, u32* dataSize, void* out) {
        return 0;
    }

    virtual int setProperty(u32 propID, u32 dataSize, const void* out) {
        switch (propID) {
            case kExtAudioFileProperty_ClientDataFormat:
                assert(dataSize == sizeof(AudioStreamBasicDescription));
                memcpy(&clientDataFormat, out, dataSize);
                clientDataFormatSet = true;
                break;
        }

        return 0;
    }

    virtual ~OpaqueAudioFileID() {
    }
};

class AudioFileOGG : public OpaqueAudioFileID {
    stb_vorbis* _handle;
    EbrFile* _file;

    AudioFileOGG(stb_vorbis* handle, EbrFile* file) : _handle(handle), _file(file) {
    }

public:
    ~AudioFileOGG() {
        if (_handle) {
            stb_vorbis_close(_handle);
            _handle = 0;
        }
        if (_file) {
            EbrFclose(_file);
            _file = 0;
        }
    }

    static OpaqueAudioFileID* openURL(char* url) {
        //  Open the file using EbrFopen so that path mapping is applied
        //  (since the url will often reference / as the root of the app directory)
        EbrFile* file = EbrFopen(url, "rb");
        if (file) {
            int err = 0;

            //  Pass the FILE* handle directly to stb_vorbis
            stb_vorbis* handle = stb_vorbis_open_file(EbrNativeFILE(file), 0, &err, 0);

            if (handle && err == 0) {
                return new AudioFileOGG(handle, file);
            }

            TraceError(TAG, L"[OGG] OGG open error: %d", err);
        }
        return 0;
    }

    virtual int read(u32* outFrameCount, AudioBufferList* buffers) {
        // Right now we only support reading into one buffer
        if (buffers->mNumberBuffers != 1) {
            UNIMPLEMENTED_WITH_MSG("OGG decoding only supported with 1 AudioBuffer");
            *outFrameCount = 0;
            return 0;
        }

        u32 numBytes = buffers->mBuffers[0].mDataByteSize;
        int ret = readBytes(0, &numBytes, buffers->mBuffers[0].mData);
        *outFrameCount = numBytes / 2;

        return ret;
    }

    int readBytes(i64 start, u32* numBytes, void* buffer) {
        int remainingShorts = *numBytes / 2;
        short* data = (short*)buffer;
        stb_vorbis_info info = stb_vorbis_get_info(_handle);

        *numBytes = 0;
        for (;;) {
            int n = stb_vorbis_get_frame_short_interleaved(_handle, info.channels, data, remainingShorts);

            // Are we done?
            if (n == 0) {
                break;
            }

            data += n * info.channels;
            remainingShorts -= n * info.channels;
            *numBytes += n * info.channels * 2;
        }

        return 0;
    }

    u32 getProperty(u32 propID, u32* dataSize, void* out) {
        stb_vorbis_info info = stb_vorbis_get_info(_handle);
        switch (propID) {
            case kExtAudioFileProperty_FileLengthFrames: {
                *(i64*)out = stb_vorbis_stream_length_in_samples(_handle);
                break;
            }

            case kExtAudioFileProperty_FileDataFormat:
            case kAudioFilePropertyDataFormat: {
                AudioStreamBasicDescription* desc = (AudioStreamBasicDescription*)out;
                desc->mFormatID = 'lpcm';
                desc->mChannelsPerFrame = info.channels;
                desc->mSampleRate = info.sample_rate;
                desc->mBytesPerFrame = info.channels * sizeof(short);
                desc->mBitsPerChannel = 16;

                // This packet information confuses me, we don't really support it in the
                // same way...
                desc->mFramesPerPacket = 1;
                desc->mBytesPerPacket = sizeof(short) * info.channels;

                break;
            }

            default:
                TraceError(TAG, L"[OGG] Unrecognized property for getProperty: %d", propID);
                break;
        }

        return 0;
    }
};

class AudioFileWAV : public OpaqueAudioFileID {
    struct Header {
        u16 formatTag;
        u16 channels;
        u32 samplesPerSec;
        u32 avgBytesPerSec;
        u16 blockAlign;
        u16 bitsPerSample;
    } _header;

    struct ChunkHeader {
        char chunkId[4];
        u32 dataSize;
    } _dataChunk;

    EbrFile* _file;

    AudioFileWAV(Header header, ChunkHeader dataChunk, EbrFile* f) : _header(header), _dataChunk(dataChunk), _file(f) {
        fileFormat.mFormatID = 'lpcm';
        fileFormat.mChannelsPerFrame = _header.channels;
        fileFormat.mSampleRate = _header.samplesPerSec;
        fileFormat.mBytesPerFrame = _header.channels * _header.bitsPerSample / 8;
        fileFormat.mBitsPerChannel = _header.bitsPerSample;

        // This packet information confuses me, we don't really support it in the
        // same way...
        fileFormat.mFramesPerPacket = 1024; // maybe incorrect??
        fileFormat.mBytesPerPacket = _header.channels * _header.bitsPerSample / 8;
    }

public:
    static OpaqueAudioFileID* openURL(char* url) {
        EbrFile* f = EbrFopen(url, "rb");
        if (!f)
            return 0;

        char id[4];
        EbrFread(id, sizeof(id), 1, f);
        if (strncmp(id, "RIFF", 4) != 0) {
            TraceError(TAG, L"Tried to open %hs as WAV, it's not", url);
            EbrFclose(f);
            return 0;
        }

        OpaqueAudioFileID* ret = openFile(f);
        if (!ret) {
            TraceError(TAG, L"Failed to open %hs as a WAV", url);
            EbrFclose(f);
            return 0;
        }

        return ret;
    }

    static OpaqueAudioFileID* openFile(EbrFile* f) {
        u32 size;
        char id[4];
        EbrFread(&size, sizeof(size), 1, f);
        EbrFread(&id, 1, sizeof(id), f);
        if (strncmp(id, "WAVE", 4) != 0) {
            TraceError(TAG, L"malformed WAV file");
            return 0;
        }

        ChunkHeader cheader;
        EbrFread(&cheader, sizeof(cheader), 1, f);
        if (strncmp(cheader.chunkId, "fmt ", 4) != 0) {
            TraceError(TAG, L"WAV Expected to get a fmt tag first");
            return 0;
        }

        // Grab the main header:
        Header header;
        EbrFread(&header, sizeof(header), 1, f);

        //  Search for the data chunk
        ChunkHeader dheader;
        while (!EbrFeof(f)) {
            EbrFread(&dheader, sizeof(dheader), 1, f);
            if (memcmp(dheader.chunkId, "data", 4) == 0)
                break;

            int size = (int)dheader.dataSize;
            if (size < 0) {
                TraceError(TAG, L"Bad data chunk size");
                return 0;
            }
            int ret = EbrFseek(f, dheader.dataSize, SEEK_CUR);
            if (ret != 0) {
                TraceError(TAG, L"Error seeking in WAV file");
                return 0;
            }
        }

        // We leave the file position right where it's ready to go for the main data
        return new AudioFileWAV(header, dheader, f);
    }

    int readBytes(i64 start, u32* numBytes, void* buffer) {
        if (start != 0) {
            TraceError(TAG, L"Attempting to read WAV with non-zero offset, unsupported.");
            return -1;
        }

        int readSize = min(*numBytes, _dataChunk.dataSize);
        EbrFread(buffer, readSize, 1, _file);
        *numBytes = readSize;

        return 0;
    }

    int read(u32* outFrameCount, AudioBufferList* buffers) {
        assert(buffers->mNumberBuffers == 1);

        if (clientDataFormatSet) {
            BYTE sampleBuffer[512];

            //  Only supports PCM 8-bit upconversion to 16-bit
            assert(clientDataFormat.mChannelsPerFrame == fileFormat.mChannelsPerFrame);
            assert(clientDataFormat.mSampleRate == fileFormat.mSampleRate);

            int sampleBufMaxFrames = sizeof(sampleBuffer) / fileFormat.mBytesPerFrame;
            int framesLeft = buffers->mBuffers[0].mDataByteSize / clientDataFormat.mBytesPerFrame;
            BYTE* bufferOut = (BYTE*)buffers->mBuffers[0].mData;

            while (framesLeft > 0) {
                u32 framesToRead = std::min(framesLeft, sampleBufMaxFrames);
                u32 bytesToRead = framesToRead * fileFormat.mBytesPerFrame;
                readBytes(0, &bytesToRead, sampleBuffer);

                if (clientDataFormat.mBitsPerChannel == fileFormat.mBitsPerChannel) {
                    memcpy(bufferOut, sampleBuffer, bytesToRead);
                    bufferOut += bytesToRead;
                } else {
                    if (clientDataFormat.mBitsPerChannel == 16 && fileFormat.mBitsPerChannel == 8) {
                        unsigned char* bufferIn = (unsigned char*)sampleBuffer;
                        signed short* sampleBufferOut = (signed short*)bufferOut;
                        u32 numSamples = framesToRead * fileFormat.mChannelsPerFrame;

                        while (numSamples > 0) {
                            (*sampleBufferOut) = ((signed short)(*bufferIn) - 128) * 256;
                            sampleBufferOut++;
                            bufferIn++;
                            numSamples--;
                        }

                        bufferOut += framesToRead * clientDataFormat.mBytesPerFrame;
                    } else {
                        assert(0);
                    }
                }

                framesLeft -= framesToRead;
            }
        } else {
            short* data = (short*)buffers->mBuffers[0].mData;

            u32 byteCount = buffers->mBuffers[0].mDataByteSize;
            readBytes(0, &byteCount, buffers->mBuffers[0].mData);

            *outFrameCount = byteCount / (_header.channels * sizeof(short));
        }

        return 0;
    }

    u32 getProperty(u32 propID, u32* dataSize, void* out) {
        switch (propID) {
            case kExtAudioFileProperty_FileLengthFrames: {
                // Subchunk2Size    == NumSamples * NumChannels * BitsPerSample/8
                // => NumSamples == DataSize / (NumChannels * BitsPerSample/8)
                *(i64*)out = _dataChunk.dataSize / (_header.channels * _header.bitsPerSample / 8);
                break;
            }

            case kExtAudioFileProperty_FileDataFormat:
            case kAudioFilePropertyDataFormat: {
                AudioStreamBasicDescription* desc = (AudioStreamBasicDescription*)out;
                memcpy(desc, &fileFormat, sizeof(AudioStreamBasicDescription));
                break;
            }

            case kAudioFilePropertyAudioDataByteCount: {
                *(u64*)out = _dataChunk.dataSize;
                break;
            }

            default:
                TraceError(TAG, L"[WAV] Unrecognized property for getProperty: %d", propID);
                break;
        }

        return 0;
    }

    virtual ~AudioFileWAV() {
        if (_file) {
            EbrFclose(_file);
            _file = 0;
        }
    }
};

class AudioFileCAF : public OpaqueAudioFileID {
    CAFDecoder _decoder;

    // Storing this in here really sucks but we can't really know until
    // we've read it all.. Refactor decoder?
    std::vector<i16> _data;

public:
    static OpaqueAudioFileID* openURL(char* url) {
        EbrFile* f = EbrFopen(url, "rb");
        if (!f) {
            TraceError(TAG, L"CAF %hs doesn't exist..", url);
            return NULL;
        }

        AudioFileCAF* self = new AudioFileCAF;
        if (!self->_decoder.InitForRead(f)) {
            TraceError(TAG, L"CAF %hs has an unsupported format..", url);
            return NULL;
        }

        i16 buffer[1024];
        while (true) {
            uint numBytes = sizeof(buffer) / 2;
            self->_decoder.ReadBuf(buffer, numBytes);

            if (numBytes == 0) {
                // Done!
                break;
            }

            self->_data.insert(self->_data.end(), buffer, buffer + numBytes / 2);
        }

        return self;
    }

    u32 getProperty(u32 propID, u32* dataSize, void* out) {
        // Note that we NEED to do a copy here since this is not aligned sanely.
        // Any access through a pointer/reference will cause a SIGBUS on ~win32.
        OutputDescription outDesc = _decoder.OutputFormat;

        switch (propID) {
            case kExtAudioFileProperty_FileLengthFrames: {
                TraceVerbose(TAG, L"CAF getting filelengthframes");
                *(i64*)out = _data.size() / outDesc.mChannelsPerFrame;
                break;
            }

            case kExtAudioFileProperty_FileDataFormat:
            case kAudioFilePropertyDataFormat: {
                TraceVerbose(TAG, L"CAF getting data format");
                AudioStreamBasicDescription* desc = (AudioStreamBasicDescription*)out;
                desc->mFormatID = 'lpcm';
                desc->mChannelsPerFrame = outDesc.mChannelsPerFrame;
                desc->mSampleRate = outDesc.mSampleRate;
                desc->mBytesPerFrame = outDesc.mChannelsPerFrame * sizeof(short);
                desc->mBitsPerChannel = outDesc.mBitsPerChannel;

                // This packet information confuses me, we don't really support it in the
                // same way...
                desc->mFramesPerPacket = 1024;
                desc->mBytesPerPacket = sizeof(short) * outDesc.mChannelsPerFrame;

                break;
            }

            case kAudioFilePropertyAudioDataByteCount: {
                TraceVerbose(TAG, L"CAF getting byte count");
                *(u64*)out = _data.size() * sizeof(short);
                break;
            }

            default:
                TraceError(TAG, L"[CAF] Unrecognized property for getProperty: %d", propID);
                break;
        }

        return 0;
    }

    int read(u32* outFrameCount, AudioBufferList* buffers) {
        return 0;
    }

    int readBytes(i64 start, u32* numBytes, void* buffer) {
        if (start != 0) {
            TraceError(TAG, L"Attempting to read CAF with non-zero offset, unsupported.");
            return -1;
        }

        int readSize = min(*numBytes, _data.size() * 2);
        memcpy(buffer, &*_data.begin(), readSize);
        // fread(buffer, readSize, 1, _file);
        *numBytes = readSize;

        return 0;
    }
};

class OpaqueExtAudioFile {
public:
    AudioFileID pAudioFile;
    bool ownsAudioFile;

    OpaqueExtAudioFile(AudioFileID pAudio, bool owns) : pAudioFile(pAudio), ownsAudioFile(owns) {
    }

    ~OpaqueExtAudioFile() {
        if (ownsAudioFile) {
            delete pAudioFile;
        }
        pAudioFile = NULL;
    }
};

/**
 @Status Caveat
 @Notes Only file:// URLs supported
*/
OSStatus AudioFileOpenURL(CFURLRef url, AudioFilePermissions permissions, AudioFileTypeID type, AudioFileID _Nullable* out) {
    char* filename = (char*)[[static_cast<NSURL*>(url) path] UTF8String];
    EbrFile* f = EbrFopen(filename, "rb");
    if (!f) {
        TraceError(TAG, L"Could not find audio file %hs", filename);
        return 0;
    }

    char header[4];
    EbrFread(&header, sizeof(header), 1, f);
    EbrFclose(f);

    // Try to figure out what this is:
    if (out) {
        if (strncmp(header, "OggS", 4) == 0) {
            *out = AudioFileOGG::openURL(filename);
        } else if (strncmp(header, "RIFF", 4) == 0) {
            *out = AudioFileWAV::openURL(filename);
        } else if (strncmp(header, "caff", 4) == 0) {
            *out = AudioFileCAF::openURL(filename);
        } else if (strncmp(header, "ID3", 3) == 0) {
            TraceError(TAG, L"MP3s not supported!");
            return 1234;
        } else {
            TraceError(TAG, L"What is %hs?!", filename);
            return 1234;
        }
    }

    return 0;
}

class EbrCallbackFile : public EbrFile {
private:
    void* funcContext;
    AudioFile_ReadProc readFunc;
    AudioFile_WriteProc writeFunc;
    AudioFile_GetSizeProc getSizeFunc;
    AudioFile_SetSizeProc setSizeFunc;
    DWORD position;

public:
    EbrCallbackFile(
        void* context, AudioFile_ReadProc read, AudioFile_WriteProc write, AudioFile_GetSizeProc getSize, AudioFile_SetSizeProc setSize) {
        funcContext = context;
        readFunc = read;
        writeFunc = write;
        getSizeFunc = getSize;
        setSizeFunc = setSize;
        position = 0;
    }

    int Close() {
        return 0;
    }

    size_t Read(void* dest, size_t elem, size_t count) {
        size_t readCount = elem * count;
        uint32_t amtRead = 0;
        unsigned int status = readFunc(funcContext, position, readCount, dest, &amtRead);
        position += amtRead;

        return amtRead;
    }
};

/**
 @Status Interoperable
*/
DWORD AudioFileOpenWithCallbacks(void* context,
                                 AudioFile_ReadProc readFunc,
                                 AudioFile_WriteProc writeFunc,
                                 AudioFile_GetSizeProc getSizeFunc,
                                 AudioFile_SetSizeProc setSizeFunc,
                                 DWORD typeHint,
                                 AudioFileID _Nullable* out) {
    EbrCallbackFile* callbackFP = new EbrCallbackFile(context, readFunc, writeFunc, getSizeFunc, setSizeFunc);
    EbrFile* in = EbrAllocFile(callbackFP);

    char header[4] = { 0 };
    EbrFread(&header, sizeof(header), 1, in);

    // Try to figure out what this is:
    if (out) {
        if (strncmp(header, "RIFF", 4) == 0) {
            *out = AudioFileWAV::openFile(in);
        } else {
            TraceError(TAG, L"What is this format?!");
            return 1234;
        }
    }

    return 0;
}

/**
 @Status Interoperable
*/
OSStatus AudioFileCreateWithURL(
    CFURLRef url, AudioFileTypeID type, const AudioStreamBasicDescription* format, UInt32 inFlags, AudioFileID _Nullable* out) {
    TraceWarning(TAG, L"_AudioFileCreateWithURL not supported");
    if (out) {
        *out = 0;
    }

    return 0;
}

/**
 @Status Interoperable
*/
OSStatus AudioFileClose(AudioFileID fileID) {
    delete fileID;
    return 0;
}

/**
 @Status Caveat
 @Notes Limited properties supported depending on codec
*/
OSStatus AudioFileGetProperty(AudioFileID fileID, AudioFilePropertyID propID, UInt32* ioDataSize, void* propOutData) {
    if (fileID == NULL) {
        return 1234;
    }

    return fileID->getProperty(propID, ioDataSize, propOutData);
}

/**
 @Status Caveat
 @Notes Limited properties supported depending on codec
*/
DWORD AudioFileGetPropertyInfo(AudioFileID fileID, DWORD propID, DWORD* outDataSize, DWORD* isWritable) {
    if (isWritable) {
        *isWritable = FALSE;
    }

    switch (propID) {
        case kAudioFilePropertyFileFormat:
            *outDataSize = 4;
            break;

        case kAudioFilePropertyDataFormat: {
            *outDataSize = sizeof(AudioStreamBasicDescription);
        } break;

        case kAudioFilePropertyMagicCookieData: {
            *outDataSize = 4;
        } break;

        case kAudioFilePropertyAudioDataByteCount: {
            *outDataSize = sizeof(DWORD);
        } break;

        default:
            *outDataSize = 0;
            break;
    }

    return (DWORD)0;
}

/**
 @Status Caveat
 @Notes useCached parameter not supported
*/
OSStatus AudioFileReadBytes(AudioFileID fileID, Boolean useCached, SInt64 startByte, UInt32* ioNumBytes, void* outBuffer) {
    return fileID->readBytes(startByte, ioNumBytes, outBuffer);
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileReadPacketData(AudioFileID fileID,
                                 Boolean useCached,
                                 UInt32* outNumBytes,
                                 AudioStreamPacketDescription* packetDescs,
                                 SInt64 firstPacket,
                                 UInt32* numPackets,
                                 void* outBuf) {
    UNIMPLEMENTED();
    TraceWarning(TAG, L"AudioFileReadPacketData not supported");

    *outNumBytes = 0;
    *numPackets = 0;

    return 0;
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileReadPackets(AudioFileID fileID,
                              Boolean useCached,
                              UInt32* outNumBytes,
                              AudioStreamPacketDescription* packetDescs,
                              SInt64 firstPacket,
                              UInt32* numPackets,
                              void* outBuf) {
    UNIMPLEMENTED();
    if (fileID == NULL) {
        *outNumBytes = 0;
        return 1234;
    }

    return 0;
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileInitializeWithCallbacks(void* inClientData,
                                          AudioFile_ReadProc inReadFunc,
                                          AudioFile_WriteProc inWriteFunc,
                                          AudioFile_GetSizeProc inGetSizeFunc,
                                          AudioFile_SetSizeProc inSetSizeFunc,
                                          AudioFileTypeID inFileType,
                                          const AudioStreamBasicDescription* inFormat,
                                          AudioFileFlags inFlags,
                                          AudioFileID _Nullable* outAudioFile) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileWriteBytes(AudioFileID inAudioFile, Boolean inUseCache, SInt64 inStartingByte, UInt32* ioNumBytes, const void* inBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileWritePackets(AudioFileID inAudioFile,
                               Boolean inUseCache,
                               UInt32 inNumBytes,
                               const AudioStreamPacketDescription* inPacketDescriptions,
                               SInt64 inStartingPacket,
                               UInt32* ioNumPackets,
                               const void* inBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileSetProperty(AudioFileID inAudioFile, AudioFilePropertyID inPropertyID, UInt32 inDataSize, const void* inPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileCountUserData(AudioFileID inAudioFile, UInt32 inUserDataID, UInt32* outNumberItems) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileGetUserDataSize(AudioFileID inAudioFile, UInt32 inUserDataID, UInt32 inIndex, UInt32* outUserDataSize) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileRemoveUserData(AudioFileID inAudioFile, UInt32 inUserDataID, UInt32 inIndex) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileSetUserData(AudioFileID inAudioFile, UInt32 inUserDataID, UInt32 inIndex, UInt32 inUserDataSize, const void* inUserData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileGetUserData(AudioFileID inAudioFile, UInt32 inUserDataID, UInt32 inIndex, UInt32* ioUserDataSize, void* outUserData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileGetGlobalInfoSize(AudioFilePropertyID inPropertyID, UInt32 inSpecifierSize, void* inSpecifier, UInt32* outDataSize) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileGetGlobalInfo(
    AudioFilePropertyID inPropertyID, UInt32 inSpecifierSize, void* inSpecifier, UInt32* ioDataSize, void* outPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileOptimize(AudioFileID inAudioFile) {
    UNIMPLEMENTED();
    return StubReturn();
}

extern "C" OSStatus _ExtAudioFileDispose(ExtAudioFileRef fileID) {
    delete fileID;
    return 0;
}

extern "C" OSStatus _ExtAudioFileOpenURL(CFURLRef url, ExtAudioFileRef* out) {
    AudioFileID audioFile = NULL;
    int ret = AudioFileOpenURL(url, kAudioFileReadPermission, 0, &audioFile);

    if (audioFile) {
        *out = new OpaqueExtAudioFile(audioFile, true);
    }

    return ret;
}

extern "C" OSStatus _ExtAudioFileWrapAudioFileID(AudioFileID fileID, Boolean writing, ExtAudioFileRef* out) {
    *out = new OpaqueExtAudioFile(fileID, false);

    return 0;
}

extern "C" OSStatus _ExtAudioFileGetProperty(ExtAudioFileRef fileID, ExtAudioFilePropertyID propID, UInt32* ioDataSize, void* propOutData) {
    if (fileID) {
        return fileID->pAudioFile->getProperty(propID, ioDataSize, propOutData);
    } else {
        return kExtAudioFileError_InvalidProperty;
    }
}

extern "C" OSStatus _ExtAudioFileSetProperty(ExtAudioFileRef fileID,
                                             ExtAudioFilePropertyID propID,
                                             UInt32 ioDataSize,
                                             const void* propInData) {
    fileID->pAudioFile->setProperty(propID, ioDataSize, propInData);
    return 0;
}

extern "C" OSStatus _ExtAudioFileRead(ExtAudioFileRef fileID, UInt32* numFrames, AudioBufferList* pData) {
    if (fileID == NULL) {
        *numFrames = 0;
        return 1234;
    }
    fileID->pAudioFile->read(numFrames, pData);

    return 0;
}