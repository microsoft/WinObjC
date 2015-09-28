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

#include "Starboard.h"
#include "AudioToolbox/AudioFile.h"
#include "CAFDecoder.h"

const SInt32 CAFDecoder::kPredTolerance = 0x007F;
const UInt32 CAFDecoder::kIndexMask = 0x007F;
const UInt32 CAFDecoder::kPredictorMask = 0xFF80;

const UInt16 CAFDecoder::kStepTableIndexMask = 0x007F;
const SInt32 CAFDecoder::kPredictorTolerance = 0x0000007F;
const SInt16 CAFDecoder::sIndexTable[16] = { -1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8 };
const SInt16 CAFDecoder::sStepTable[89] = {
    7,    8,     9,     10,    11,    12,    13,    14,    16,    17,    19,    21,    23,    25,   28,
    31,   34,    37,    41,    45,    50,    55,    60,    66,    73,    80,    88,    97,    107,  118,
    130,  143,   157,   173,   190,   209,   230,   253,   279,   307,   337,   371,   408,   449,  494,
    544,  598,   658,   724,   796,   876,   963,   1060,  1166,  1282,  1411,  1552,  1707,  1878, 2066,
    2272, 2499,  2749,  3024,  3327,  3660,  4026,  4428,  4871,  5358,  5894,  6484,  7132,  7845, 8630,
    9493, 10442, 11487, 12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

SInt16 CFSwapInt16BigToHost(SInt16 val) {
    return ((uint16_t)val & 0xFF00) >> 8 | ((uint16_t)val & 0x00FF) << 8;
}

void CAFDecoder::CheckState(const Byte* inInputData, ChannelState& ioChannelState) {
    SInt16 s = CFSwapInt16BigToHost(*((short*)inInputData));
    SInt16 theStepTableIndex = s & kIndexMask; // get stored index
    s &= kPredictorMask; // get stored thePredictedSample
    SInt32 thePredictedSample = s; // make sure it gets sign-extended!

    if (theStepTableIndex == ioChannelState.mStepTableIndex) // indexes match
    {
        // calculate theDifference between state and stored value
        SInt32 theDifference = thePredictedSample - ioChannelState.mPredictedSample; 
        if (theDifference < 0) {
            theDifference = -theDifference;
        }

        // is difference greater than tolerance?
        if (theDifference <= kPredTolerance) {
            // no, so state is good
            return; 
        }
    }

    ioChannelState.mPredictedSample = thePredictedSample; // use stored state
    ioChannelState.mStepTableIndex = theStepTableIndex;
}

void CAFDecoder::DecodeChannelSInt16(ChannelState& ioChannelState,
                                     UInt32 inNumberChannels,
                                     UInt32 inDecodeChannel,
                                     UInt32 inNumberPacketsToDecode,
                                     const Byte* inInputData,
                                     SInt16* outOutputData) {
    //  This decoder can only decode one channel at a time.
    //  Each channel in a packet of frames is encoded separately and
    //  the resulting channel packets are interleaved in channel order.

    //  We need to figure out how to skip through the input and output buffers
    //  and point at the appropriate place in the data to start off
    UInt32 theInputStride = (inNumberChannels - 1) * kIMA4PacketBytes + 2;
    Byte* theInputData = const_cast<Byte*>(inInputData) + (inDecodeChannel * kIMA4PacketBytes);
    UInt32 theOutputStride = inNumberChannels;

    SInt32 theDifference;
    SInt32 theCode = 0;
    UInt32 theTemporaryInputData = 0; /* initialize so warnings go away */

    SInt16* theOutputData = const_cast<SInt16*>(outOutputData) + inDecodeChannel;

    if (inNumberPacketsToDecode == 0)
        return;

    CheckState(theInputData, ioChannelState); /* make sure state predictors match stream */
    theInputData += 2; /* skip first predictor */

    SInt32 thePredictedSample = ioChannelState.mPredictedSample; /* continue where we left off last time */
    SInt32 theStepTableIndex = ioChannelState.mStepTableIndex;
    SInt32 theStep = sStepTable[theStepTableIndex];

    for (; inNumberPacketsToDecode > 0; --inNumberPacketsToDecode) {
        // EbrDebugLog("inNumberPacketsToDecode %d\n", inNumberPacketsToDecode);
        for (UInt32 theNumberSamplesLeft = kIMAFramesPerPacket; theNumberSamplesLeft > 0; --theNumberSamplesLeft) {
            if (theNumberSamplesLeft & 1) /* two samples per input char */
                theCode = theTemporaryInputData >> 4;
            else {
                // EbrDebugLog("IN %02X\n", *theInputData & 255);
                theTemporaryInputData = (UInt32)*theInputData++; /* buffer two ADPCM nibbles */
                theCode = theTemporaryInputData & 0x0F;
            }

            theDifference = 0; /* compute new sample estimate thePredictedSample */
            if (theCode & 4)
                theDifference += theStep;
            if (theCode & 2)
                theDifference += theStep >> 1;
            if (theCode & 1)
                theDifference += theStep >> 2;

            theDifference += theStep >> 3;
            if (theCode & 8)
                theDifference = -theDifference;

            thePredictedSample += theDifference;

            //  check for overflow
            if (thePredictedSample > 32767) {
                thePredictedSample = 32767;
            } else if (thePredictedSample < -32768) {
                thePredictedSample = -32768;
            }

            // EbrDebugLog("   theCode %02X  theDifference %d\n", theCode, theDifference);
            // EbrDebugLog("OUT %02X %d   \n", thePredictedSample & 255, thePredictedSample);

            *theOutputData = thePredictedSample;
            theOutputData += theOutputStride;

            theStepTableIndex += sIndexTable[theCode]; /* compute new stepsize step */
            if (theStepTableIndex < 0)
                theStepTableIndex = 0;
            else if (theStepTableIndex > 88)
                theStepTableIndex = 88;
            theStep = sStepTable[theStepTableIndex];
            // EbrDebugLog("   theStep %d  theStepTableIndex %d\n", theStep, theStepTableIndex);
        }

        theInputData += theInputStride;
    }

    ioChannelState.mPredictedSample = thePredictedSample;
    ioChannelState.mStepTableIndex = theStepTableIndex;
}

uint32_t int32Swap(uint32_t val) {
    return (val & 0xFF000000) >> 24 | (val & 0x00FF0000) >> 8 | (val & 0x0000FF00) << 8 | (val & 0x000000FF) << 24;
}

uint64_t int64Swap(uint64_t val) {
    unsigned char* curByte = (unsigned char*)&val;
    unsigned char output[8];

    for (int i = 0; i < 8; i++) {
        output[7 - i] = *curByte++;
    }

    uint64_t ret = 0;
    memcpy(&ret, output, 8);
    return ret;
}

double dSwap(double val) {
    unsigned char* curByte = (unsigned char*)&val;
    unsigned char output[8];

    for (int i = 0; i < 8; i++) {
        output[7 - i] = *curByte++;
    }

    double ret = 0;
    memcpy(&ret, output, 8);
    return ret;
}

enum {
    kAudioCodecProduceOutputPacketSuccess,
    kAudioCodecProduceOutputPacketNeedsMoreInputData,
    kAudioCodecProduceOutputPacketSuccessHasMore
} Result;

int CAFDecoder::GetUsedInputBufferByteSize(EbrFile* fpIn) {
    int cur = EbrFtell(fpIn);
    EbrFseek(fpIn, 0, SEEK_END);
    int left = EbrFtell(fpIn) - cur;
    EbrFseek(fpIn, cur, SEEK_SET);

    return left;
}

Byte* CAFDecoder::GetBytes(EbrFile* fpIn, int len) {
    Byte* ret = (Byte*)malloc(len);

    EbrFread(ret, 1, len, fpIn);

    return ret;
}

UInt32 CAFDecoder::ProduceOutputPackets(EbrFile* fpIn,
                                        ChannelStateList& mChannelStateList,
                                        void* outOutputData,
                                        UInt32& ioOutputDataByteSize,
                                        UInt32& ioNumberPackets,
                                        OutputDescription& mOutputFormat,
                                        CAFAudioDescription& mInputFormat) {
    if (isPcm) {
        int read =
            EbrFread(outOutputData, cafDesc.mBytesPerPacket, ioOutputDataByteSize / cafDesc.mBytesPerPacket, fpIn);
        ioNumberPackets = read;
        ioOutputDataByteSize = ioNumberPackets * cafDesc.mBytesPerPacket;
        return 0;
    }

    //  setup the return value, by assuming that everything is going to work
    UInt32 theAnswer = kAudioCodecProduceOutputPacketSuccess;

    //  Note that the decoder doesn't suffer from the same problem the encoder
    //  does with not having enough data for a packet, since the encoded data
    //  is always going to be in whole packets.

    //  clamp the number of packets to produce based on what is available in the input buffer
    UInt32 inputPacketSize = mInputFormat.mBytesPerPacket;
    UInt32 numberOfInputPackets = GetUsedInputBufferByteSize(fpIn) / inputPacketSize;
    if (ioNumberPackets < numberOfInputPackets) {
        numberOfInputPackets = ioNumberPackets;
    } else if (ioNumberPackets > numberOfInputPackets) {
        ioNumberPackets = numberOfInputPackets;

        //  this also means we need more input to satisfy the request so set the return value
        theAnswer = kAudioCodecProduceOutputPacketNeedsMoreInputData;
    }

    // We only produce 1 at a time
    if (ioNumberPackets > 1 && numberOfInputPackets > 1) {
        numberOfInputPackets = ioNumberPackets = 1;
        theAnswer = kAudioCodecProduceOutputPacketSuccessHasMore;
    }

    UInt32 inputByteSize = numberOfInputPackets * inputPacketSize;

    if (ioNumberPackets > 0) {
        //  make sure that there is enough space in the output buffer for the encoded data
        //  it is an error to ask for more output than you pass in buffer space for
        UInt32 theOutputByteSize = ioNumberPackets * mInputFormat.mFramesPerPacket * mOutputFormat.mBytesPerFrame;
        // ThrowIf(ioOutputDataByteSize < theOutputByteSize,
        // static_cast<OSStatus>(kAudioCodecNotEnoughBufferSpaceError), "ACAppleIMA4Decoder::ProduceOutputPackets: not
        // enough space in the output buffer");

        //  set the return value
        ioOutputDataByteSize = theOutputByteSize;

        //  decode the input data for each channel
        Byte* theInputData = GetBytes(fpIn, inputByteSize);
        SInt16* theOutputData = reinterpret_cast<SInt16*>(outOutputData);

        ChannelStateList::iterator theIterator = mChannelStateList.begin();
        for (int theChannelIndex = 0; theChannelIndex < mOutputFormat.mChannelsPerFrame; ++theChannelIndex) {
            // EbrDebugLog("->DecodeChannel %d %d %d %08X %08X\n", mOutputFormat.mChannelsPerFrame, theChannelIndex,
            // ioNumberPackets, theInputData, theOutputData);
            DecodeChannelSInt16(*theIterator,
                                mOutputFormat.mChannelsPerFrame,
                                theChannelIndex,
                                ioNumberPackets,
                                theInputData,
                                theOutputData);
            std::advance(theIterator, 1);
        }

        free(theInputData);

        // ConsumeInputData(inputByteSize);
    } else {
        //  set the return value since we're not actually doing any work
        ioOutputDataByteSize = 0;
    }

    /*
    if((theAnswer == kAudioCodecProduceOutputPacketSuccess) && (GetUsedInputBufferByteSize() >= inputPacketSize))
    {
    //  we satisfied the request, and there's at least one more full packet of data we can decode
    //  so set the return value
    theAnswer = kAudioCodecProduceOutputPacketSuccessHasMore;
    }
    */

    return theAnswer;
}

bool CAFDecoder::InitForRead(EbrFile* in) {
    fpIn = in;
    CAFFileHeader header;
    EbrFread(&header, 1, sizeof(CAFFileHeader), fpIn);
    bool stop = false;
    isPcm = false;

    while (!EbrFeof(fpIn) && !stop) {
        CAFChunkHeader chunkHeader;
        EbrFread(&chunkHeader, 1, sizeof(CAFChunkHeader), fpIn);
        chunkHeader.mChunkType = int32Swap(chunkHeader.mChunkType);
        chunkHeader.mChunkSize = int64Swap(chunkHeader.mChunkSize);

        int64_t chunkEnd = EbrFtell(fpIn) + chunkHeader.mChunkSize;
        switch (chunkHeader.mChunkType) {
            case CAF_StreamDescriptionChunkID:
                EbrFread(&cafDesc, 1, sizeof(CAFAudioDescription), fpIn);
                cafDesc.mSampleRate = dSwap(cafDesc.mSampleRate);

                cafDesc.mFormatID = int32Swap(cafDesc.mFormatID);

                switch (cafDesc.mFormatID) //  switch(me)
                {
                    case 'lpcm':
                        isPcm = true;
                        break;

                    case 'ima4':
                        isPcm = false;
                        break;

                    default:
                        EbrDebugLog("Unrecognized CAF format %d\n", cafDesc.mFormatFlags);
                        return false;
                }

                cafDesc.mFormatFlags = int32Swap(cafDesc.mFormatFlags);
                cafDesc.mBytesPerPacket = int32Swap(cafDesc.mBytesPerPacket);
                cafDesc.mFramesPerPacket = int32Swap(cafDesc.mFramesPerPacket);
                cafDesc.mChannelsPerFrame = int32Swap(cafDesc.mChannelsPerFrame);
                cafDesc.mBitsPerChannel = int32Swap(cafDesc.mBitsPerChannel);
                break;

            case CAF_PacketTableChunkID:
                EbrFread(&cafPacketTbl, 1, sizeof(cafPacketTbl), fpIn);

                cafPacketTbl.mNumberPackets = int64Swap(cafPacketTbl.mNumberPackets);
                cafPacketTbl.mNumberValidFrames = int64Swap(cafPacketTbl.mNumberValidFrames);
                cafPacketTbl.mPrimingFrames = int32Swap(cafPacketTbl.mPrimingFrames);
                cafPacketTbl.mRemainderFrames = int32Swap(cafPacketTbl.mRemainderFrames);
                break;

            case CAF_AudioDataChunkID:
                //  Skip edit count
                EbrFseek(fpIn, 4, SEEK_CUR);
                dataStart = EbrFtell(fpIn);
                stop = true;

                OutputFormat.mBytesPerFrame = 2 * cafDesc.mChannelsPerFrame;
                OutputFormat.mChannelsPerFrame = cafDesc.mChannelsPerFrame;
                OutputFormat.mSampleRate = cafDesc.mSampleRate;
                OutputFormat.mBitsPerChannel = 16;

                for (int i = 0; i < OutputFormat.mChannelsPerFrame; i++) {
                    channelStates.push_back(ChannelState());
                }

                break;

            default:
                EbrFseek(fpIn, (long)chunkHeader.mChunkSize, SEEK_CUR);
                break;
        }

        if (!stop)
            EbrFseek(fpIn, (long)chunkEnd, SEEK_SET);
    }

    return true;
}

int CAFDecoder::ReadBuf(int16_t* out, uint32_t& ioOutputDataByteSize) {
    UInt32 ioNumberPackets = 1;

    ProduceOutputPackets(fpIn, channelStates, out, ioOutputDataByteSize, ioNumberPackets, OutputFormat, cafDesc);
    return ioOutputDataByteSize;
}

void CAFDecoder::Reset() {
    EbrFseek(fpIn, dataStart, SEEK_SET);

    channelStates.clear();
    for (int i = 0; i < OutputFormat.mChannelsPerFrame; i++) {
        channelStates.push_back(ChannelState());
    }
}