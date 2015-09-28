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

#include <math.h>
#include <time.h>
#include <pthread.h>
#include <algorithm>

#include "Starboard.h"
#include "Platform/EbrPlatform.h"
#include "Etc.h"

#include "stb_vorbis.h"
#include "AudioToolbox/ExtendedAudioFile.h"

typedef unsigned int uint;

typedef int64_t i64;
typedef uint64_t u64;
typedef int32_t i32;
typedef uint32_t u32;
typedef int16_t i16;
typedef uint16_t u16;

#include "AudioToolbox/AudioFile.h"

#define kExtAudioFileError_InvalidProperty -66561

class AudioFile {
protected:
    AudioStreamBasicDescription clientDataFormat;
    bool clientDataFormatSet;

    AudioStreamBasicDescription fileFormat;

public:
    AudioFile() : clientDataFormatSet(false) {
        memset(&fileFormat, 0, sizeof(fileFormat));
    }

    virtual int read(u32* outFrameCount, AudioBufferList* buffers) = 0;
    virtual int readBytes(i64 start, u32* numBytes, void* buffer) = 0;

    virtual u32 getProperty(u32 propID, u32* dataSize, void* out) = 0;
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

    virtual ~AudioFile() {
    }
};

class AudioFileOGG : public AudioFile {
    stb_vorbis* _handle;

    AudioFileOGG(stb_vorbis* handle) : _handle(handle) {
    }

public:
    ~AudioFileOGG() {
        if (_handle) {
            stb_vorbis_close(_handle);
            _handle = 0;
        }
    }

    static AudioFile* openURL(char* url) {
        int err = 0;
        stb_vorbis* handle = stb_vorbis_open_filename(url, &err, 0);

        if (handle && err == 0) {
            return new AudioFileOGG(handle);
        }
        return 0;
    }

    virtual int read(u32* outFrameCount, AudioBufferList* buffers) {
        // Right now we only support reading into one buffer
        assert(buffers->mNumberBuffers == 1);

        short* data = (short*)buffers->mBuffers[0].mData;
        *outFrameCount = buffers->mBuffers[0].mDataByteSize / 2;

        return readBytes(0, outFrameCount, buffers->mBuffers[0].mData);
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

                // This packet information confuses me, we don't really support it in the same way...
                desc->mFramesPerPacket = 1;
                desc->mBytesPerPacket = sizeof(short) * info.channels;

                break;
            }

            default:
                EbrDebugLog("[OGG] Unrecognized property for getProperty: %d\n", propID);
                break;
        }

        return 0;
    }
};

class AudioFileWAV : public AudioFile {
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

        // This packet information confuses me, we don't really support it in the same way...
        fileFormat.mFramesPerPacket = 1024; // maybe incorrect??
        fileFormat.mBytesPerPacket = _header.channels * _header.bitsPerSample / 8;
    }

public:
    static AudioFile* openURL(char* url) {
        EbrFile* f = EbrFopen(url, "rb");
        if (!f)
            return 0;

        char id[4];
        EbrFread(id, sizeof(id), 1, f);
        if (strncmp(id, "RIFF", 4) != 0) {
            EbrDebugLog("Tried to open %s as WAV, it's not\n", url);
            EbrFclose(f);
            return 0;
        }

        AudioFile* ret = openFile(f);
        if (!ret) {
            EbrDebugLog("Failed to open %s as a WAV\n", url);
            EbrFclose(f);
            return 0;
        }

        return ret;
    }

    static AudioFile* openFile(EbrFile* f) {
        u32 size;
        char id[4];
        EbrFread(&size, sizeof(size), 1, f);
        EbrFread(&id, 1, sizeof(id), f);
        if (strncmp(id, "WAVE", 4) != 0) {
            EbrDebugLog("malformed WAV file\n");
            return 0;
        }

        ChunkHeader cheader;
        EbrFread(&cheader, sizeof(cheader), 1, f);
        if (strncmp(cheader.chunkId, "fmt ", 4) != 0) {
            EbrDebugLog("WAV Expected to get a fmt tag first\n");
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
                EbrDebugLog("Bad data chunk size\n");
                return 0;
            }
            int ret = EbrFseek(f, dheader.dataSize, SEEK_CUR);
            if (ret != 0) {
                EbrDebugLog("Error seeking in WAV file\n");
                return 0;
            }
        }

        // We leave the file position right where it's ready to go for the main data
        return new AudioFileWAV(header, dheader, f);
    }

    int readBytes(i64 start, u32* numBytes, void* buffer) {
        if (start != 0) {
            EbrDebugLog("Attempting to read WAV with non-zero offset, unsupported.\n");
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
                EbrDebugLog("[WAV] Unrecognized property for getProperty: %d\n", propID);
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

#include "CAFDecoder.h"

class AudioFileCAF : public AudioFile {
    CAFDecoder _decoder;

    // Storing this in here really sucks but we can't really know until
    // we've read it all.. Refactor decoder?
    std::vector<i16> _data;

public:
    static AudioFile* openURL(char* url) {
        EbrFile* f = EbrFopen(url, "rb");
        if (!f) {
            EbrDebugLog("CAF %s doesn't exist..\n", url);
            return NULL;
        }

        AudioFileCAF* self = new AudioFileCAF;
        if (!self->_decoder.InitForRead(f)) {
            EbrDebugLog("CAF %s has an unsupported format..\n", url);
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
                EbrDebugLog("CAF getting filelengthframes\n");
                *(i64*)out = _data.size() / outDesc.mChannelsPerFrame;
                break;
            }

            case kExtAudioFileProperty_FileDataFormat:
            case kAudioFilePropertyDataFormat: {
                EbrDebugLog("CAF getting data format\n");
                AudioStreamBasicDescription* desc = (AudioStreamBasicDescription*)out;
                desc->mFormatID = 'lpcm';
                desc->mChannelsPerFrame = outDesc.mChannelsPerFrame;
                desc->mSampleRate = outDesc.mSampleRate;
                desc->mBytesPerFrame = outDesc.mChannelsPerFrame * sizeof(short);
                desc->mBitsPerChannel = outDesc.mBitsPerChannel;

                // This packet information confuses me, we don't really support it in the same way...
                desc->mFramesPerPacket = 1024;
                desc->mBytesPerPacket = sizeof(short) * outDesc.mChannelsPerFrame;

                break;
            }

            case kAudioFilePropertyAudioDataByteCount: {
                EbrDebugLog("CAF getting byte count\n");
                *(u64*)out = _data.size() * sizeof(short);
                break;
            }

            default:
                EbrDebugLog("[CAF] Unrecognized property for getProperty: %d\n", propID);
                break;
        }

        return 0;
    }

    int read(u32* outFrameCount, AudioBufferList* buffers) {
        return 0;
    }

    int readBytes(i64 start, u32* numBytes, void* buffer) {
        if (start != 0) {
            EbrDebugLog("Attempting to read CAF with non-zero offset, unsupported.\n");
            return -1;
        }

        int readSize = min(*numBytes, _data.size() * 2);
        memcpy(buffer, &*_data.begin(), readSize);
        // fread(buffer, readSize, 1, _file);
        *numBytes = readSize;

        return 0;
    }
};

OSStatus AudioFileOpenURL(CFURLRef url, SInt8 permissions, AudioFileTypeID type, AudioFileID* out) {
    char* filename = (char*)[[url path] UTF8String];
    EbrFile* f = EbrFopen(filename, "rb");
    if (!f) {
        EbrDebugLog("Could not find audio file %s\n", filename);
        return 0;
    }

    char header[4];
    EbrFread(&header, sizeof(header), 1, f);
    EbrFclose(f);

    // Try to figure out what this is:
    if (strncmp(header, "OggS", 4) == 0) {
        *out = AudioFileOGG::openURL(filename);
    } else if (strncmp(header, "RIFF", 4) == 0) {
        *out = AudioFileWAV::openURL(filename);
    } else if (strncmp(header, "caff", 4) == 0) {
        *out = AudioFileCAF::openURL(filename);
    } else if (strncmp(header, "ID3", 3) == 0) {
        EbrDebugLog("MP3s not supported!\n");
        return 1234;
    } else {
        EbrDebugLog("What is %s?!\n", filename);
        return 1234;
    }

    return 0;
}

class EbrCallbackFile : public EbrFile {
private:
    DWORD funcContext;
    DWORD readFunc, writeFunc, getSizeFunc, setSizeFunc;
    DWORD position;

public:
    EbrCallbackFile(DWORD context, DWORD read, DWORD write, DWORD getSize, DWORD setSize) {
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
        DWORD amtRead = 0;
        unsigned int status =
            (unsigned int)EbrCall(readFunc, "dddddd", funcContext, position, 0, readCount, dest, &amtRead);
        position += amtRead;

        return amtRead;
    }
};

DWORD AudioFileOpenWithCallbacks(DWORD context,
                                 DWORD readFunc,
                                 DWORD writeFunc,
                                 DWORD getSizeFunc,
                                 DWORD setSizeFunc,
                                 DWORD typeHint,
                                 AudioFile** out) {
    EbrCallbackFile* callbackFP = new EbrCallbackFile(context, readFunc, writeFunc, getSizeFunc, setSizeFunc);
    EbrFile* in = EbrAllocFile(callbackFP);

    char header[4] = { 0 };
    EbrFread(&header, sizeof(header), 1, in);

    // Try to figure out what this is:
    if (strncmp(header, "RIFF", 4) == 0) {
        *out = AudioFileWAV::openFile(in);
    } else {
        EbrDebugLog("What is this format?!\n");
        return 1234;
    }

    return 0;
}

class ExtAudioFile {
public:
    AudioFile* pAudioFile;
    bool ownsAudioFile;

    ExtAudioFile(AudioFile* pAudio, bool owns) : pAudioFile(pAudio), ownsAudioFile(owns) {
    }

    ~ExtAudioFile() {
        if (ownsAudioFile) {
            delete pAudioFile;
        }
        pAudioFile = NULL;
    }
};

typedef ExtAudioFile* ExtAudioFileRef;

OSStatus ExtAudioFileOpenURL(CFURLRef url, ExtAudioFileRef* out) {
    AudioFile* audioFile = NULL;
    int ret = AudioFileOpenURL(url, 0, 0, &audioFile);

    if (audioFile) {
        *out = new ExtAudioFile(audioFile, true);
    }

    return ret;
}

OSStatus ExtAudioFileWrapAudioFileID(AudioFileID fileID, Boolean writing, ExtAudioFileRef* out) {
    *out = new ExtAudioFile(fileID, false);

    return 0;
}

OSStatus AudioFileCreateWithURL(
    CFURLRef url, AudioFileTypeID type, const AudioStreamBasicDescription* format, UInt32 inFlags, AudioFileID* out) {
    EbrDebugLog("_AudioFileCreateWithURL not supported\n");
    *out = 0;

    return 0;
}

OSStatus AudioFileClose(AudioFileID fileID) {
    delete fileID;
    return 0;
}

OSStatus ExtAudioFileDispose(ExtAudioFileRef fileID) {
    delete fileID;
    return 0;
}

OSStatus AudioFileGetProperty(AudioFileID fileID, AudioFilePropertyID propID, UInt32* ioDataSize, void* propOutData) {
    if (fileID == NULL) {
        return 1234;
    }

    return fileID->getProperty(propID, ioDataSize, propOutData);
}

OSStatus ExtAudioFileGetProperty(ExtAudioFileRef fileID, ExtAudioFilePropertyID propID, UInt32* ioDataSize,
                                 void* propOutData) {
    if (fileID) {
        return fileID->pAudioFile->getProperty(propID, ioDataSize, propOutData);
    } else {
        return kExtAudioFileError_InvalidProperty;
    }
}

OSStatus ExtAudioFileSetProperty(ExtAudioFileRef fileID,
                                 ExtAudioFilePropertyID propID,
                                 UInt32 ioDataSize,
                                 const void* propInData) {
    fileID->pAudioFile->setProperty(propID, ioDataSize, propInData);
    return 0;
}

DWORD AudioFileGetPropertyInfo(AudioFile* fileID, DWORD propID, DWORD* outDataSize, DWORD* isWritable) {
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

OSStatus
AudioFileReadBytes(AudioFileID fileID, Boolean useCached, SInt64 startByte, UInt32* ioNumBytes, void* outBuffer) {
    return fileID->readBytes(startByte, ioNumBytes, outBuffer);
}

OSStatus ExtAudioFileSeek(ExtAudioFileRef fileID, SInt64 pos) {
    EbrDebugLog("ExtAudioFileSeek not supported\n");
    return 0;
}

OSStatus ExtAudioFileRead(ExtAudioFileRef fileID, UInt32* numFrames, AudioBufferList* pData) {
    if (fileID == NULL) {
        *numFrames = 0;
        return 1234;
    }
    fileID->pAudioFile->read(numFrames, pData);

    return 0;
}

OSStatus AudioFileReadPacketData(AudioFileID fileID,
                                 Boolean useCached,
                                 UInt32* outNumBytes,
                                 AudioStreamPacketDescription* packetDescs,
                                 SInt64 firstPacket,
                                 UInt32* numPackets,
                                 void* outBuf) {
    EbrDebugLog("AudioFileReadPacketData not supported\n");

    *outNumBytes = 0;
    *numPackets = 0;

    return 0;
}

OSStatus AudioFileReadPackets(AudioFileID fileID,
                              Boolean useCached,
                              UInt32* outNumBytes,
                              AudioStreamPacketDescription* packetDescs,
                              SInt64 firstPacket,
                              UInt32* numPackets,
                              void* outBuf) {
    if (fileID == NULL) {
        *outNumBytes = 0;
        return 1234;
    }

    return 0;
}

DWORD AudioConverterNew(AudioStreamBasicDescription* in, AudioStreamBasicDescription* out, DWORD* handle) {
    *handle = 1234;

    return 0;
}

DWORD AudioConverterFillComplexBuffer(DWORD handle,
                                      DWORD inProc,
                                      DWORD userData,
                                      DWORD* outPacketSize,
                                      AudioBufferList* outData,
                                      AudioStreamBasicDescription* out) {
    return 0;
}
