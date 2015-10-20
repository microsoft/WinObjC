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

#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include "Platform/EbrPlatform.h"

uint32_t int32Swap(uint32_t val);
uint64_t int64Swap(uint64_t val);
double dSwap(double val);

typedef struct {
    int mBytesPerFrame;
    int mChannelsPerFrame;
    int mBitsPerChannel;
    double mSampleRate;
} OutputDescription;

class CAFDecoder {
private:
    struct ChannelState {
        SInt32 mPredictedSample;
        SInt16 mStepTableIndex;

        inline ChannelState() : mPredictedSample(0), mStepTableIndex(0) {
        }
        inline void Reset() {
            mPredictedSample = 0;
            mStepTableIndex = 0;
        }
    };

    enum {
        kIMAFramesPerPacket = 64,
        kBytesPerChannelPerPacket = 32,
        kHeaderBytes = 2,
        kInputBufferPackets = 32,
        kIMA4PacketBytes = kHeaderBytes + kBytesPerChannelPerPacket
    };

    bool isPcm;
    static const SInt32 kPredTolerance;
    static const UInt32 kIndexMask;
    static const UInt32 kPredictorMask;

    static const UInt16 kStepTableIndexMask;
    static const SInt32 kPredictorTolerance;
    static const SInt16 sIndexTable[16];
    static const SInt16 sStepTable[89];

    void CheckState(const Byte* inInputData, ChannelState& ioChannelState);
    void DecodeChannelSInt16(ChannelState& ioChannelState,
                             UInt32 inNumberChannels,
                             UInt32 inDecodeChannel,
                             UInt32 inNumberPacketsToDecode,
                             const Byte* inInputData,
                             SInt16* outOutputData);

    // CAF File Header
    enum { _port_CAF_FileType = 'caff', CAF_FileVersion_Initial = 1 };

    // CAF Chunk Types
    enum {
        CAF_StreamDescriptionChunkID = 'desc',
        CAF_AudioDataChunkID = 'data',
        CAF_ChannelLayoutChunkID = 'chan',
        CAF_MagicCookieID = 'kuki',
        CAF_PacketTableChunkID = 'pakt',
        CAF_FreeTableChunkID = 'free'
    };

#pragma pack(push)
#pragma pack(1)
    struct CAFFileHeader {
        uint32_t mFileType; // 'caff'
        uint16_t mFileVersion; // initial revision set to 1
        uint16_t mFileFlags; // initial revision set to 0
    };

    struct CAFChunkHeader {
        uint32_t mChunkType; // four char code
        int64_t mChunkSize; // size in bytes of the chunk data (not including this
        // header).
        // mChunkSize is int64_t not uint64_t because negative values for
        // the data size can have a special meaning
    };

    typedef struct CAFAudioDescription {
        double mSampleRate;
        uint32_t mFormatID;
        uint32_t mFormatFlags;
        uint32_t mBytesPerPacket;
        uint32_t mFramesPerPacket;
        uint32_t mChannelsPerFrame;
        uint32_t mBitsPerChannel;
    } CAFAudioDescription;

    typedef struct CAFPacketTableHeader {
        int64_t mNumberPackets;
        int64_t mNumberValidFrames;
        int32_t mPrimingFrames;
        int32_t mRemainderFrames;

        uint8_t mPacketDescriptions[1]; // this is a variable length array of
        // mNumberPackets elements
    } CAFPacketTableHeader;

    typedef struct CAFDataChunk { uint32_t mEditCount; } CAFDataChunk;

#pragma pack(pop)

    enum {
        kAudioCodecProduceOutputPacketSuccess,
        kAudioCodecProduceOutputPacketNeedsMoreInputData,
        kAudioCodecProduceOutputPacketSuccessHasMore
    } Result;

    int GetUsedInputBufferByteSize(EbrFile* fpIn);
    Byte* GetBytes(EbrFile* fpIn, int len);

    typedef std::vector<ChannelState> ChannelStateList;

    UInt32 ProduceOutputPackets(EbrFile* fpIn,
                                ChannelStateList& mChannelStateList,
                                void* outOutputData,
                                UInt32& ioOutputDataByteSize,
                                UInt32& ioNumberPackets,
                                OutputDescription& mOutputFormat,
                                CAFAudioDescription& mInputFormat);
    EbrFile* fpIn;
    CAFAudioDescription cafDesc;
    CAFPacketTableHeader cafPacketTbl;

public:
    OutputDescription OutputFormat;
    ChannelStateList channelStates;
    int dataStart;

    bool InitForRead(EbrFile* in);
    int ReadBuf(int16_t* samplesOut, uint32_t& ioOutputDataByteSize);
    void Reset();
};
