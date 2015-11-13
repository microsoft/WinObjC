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

#ifndef _COREAUDIOTYPES_H_
#define _COREAUDIOTYPES_H_

#import <CoreFoundation/CFBase.h>

#define COREAUDIOTYPES_VERSION 1300

#define kAudioUnitSampleFractionBits 24

typedef int32_t AudioUnitSampleType;
typedef int32_t AudioChannelLayoutTag;

typedef struct {
    UInt32 mNumberChannels;
    UInt32 mDataByteSize;
    void* mData;
} AudioBuffer;

typedef struct {
    UInt32 mNumberBuffers;
    AudioBuffer mBuffers[1];
} AudioBufferList;

typedef struct {
    double mSampleRate;
    uint32_t mFormatID;
    uint32_t mFormatFlags;
    uint32_t mBytesPerPacket;
    uint32_t mFramesPerPacket;
    uint32_t mBytesPerFrame;
    uint32_t mChannelsPerFrame;
    uint32_t mBitsPerChannel;
    uint32_t mReserved;
} AudioStreamBasicDescription;

enum {
    kAudioFormatLinearPCM = 'lpcm',
    kAudioFormatAC3 = 'ac-3',
    kAudioFormat60958AC3 = 'cac3',
    kAudioFormatAppleIMA4 = 'ima4',
    kAudioFormatMPEG4AAC = 'aac ',
    kAudioFormatMPEG4CELP = 'celp',
    kAudioFormatMPEG4HVXC = 'hvxc',
    kAudioFormatMPEG4TwinVQ = 'twvq',
    kAudioFormatMACE3 = 'MAC3',
    kAudioFormatMACE6 = 'MAC6',
    kAudioFormatULaw = 'ulaw',
    kAudioFormatALaw = 'alaw',
    kAudioFormatQDesign = 'QDMC',
    kAudioFormatQDesign2 = 'QDM2',
    kAudioFormatQUALCOMM = 'Qclp',
    kAudioFormatMPEGLayer1 = '.mp1',
    kAudioFormatMPEGLayer2 = '.mp2',
    kAudioFormatMPEGLayer3 = '.mp3',
    kAudioFormatTimeCode = 'time',
    kAudioFormatMIDIStream = 'midi',
    kAudioFormatParameterValueStream = 'apvs',
    kAudioFormatAppleLossless = 'alac',
    kAudioFormatMPEG4AAC_HE = 'aach',
    kAudioFormatMPEG4AAC_LD = 'aacl',
    kAudioFormatMPEG4AAC_ELD = 'aace',
    kAudioFormatMPEG4AAC_ELD_SBR = 'aacf',
    kAudioFormatMPEG4AAC_HE_V2 = 'aacp',
    kAudioFormatMPEG4AAC_Spatial = 'aacs',
    kAudioFormatAMR = 'samr',
    kAudioFormatAudible = 'AUDB',
    kAudioFormatiLBC = 'ilbc',
    kAudioFormatDVIIntelIMA = 0x6D730011,
    kAudioFormatMicrosoftGSM = 0x6D730031,
    kAudioFormatAES3 = 'aes3'
};

enum : unsigned int {
    kAudioFormatFlagIsFloat = 0x1,
    kAudioFormatFlagIsBigEndian = 0x2,
    kAudioFormatFlagIsSignedInteger = 0x4,
    kAudioFormatFlagIsPacked = 0x8,
    kAudioFormatFlagIsAlignedHigh = 0x10,
    kAudioFormatFlagIsNonInterleaved = 0x20,
    kAudioFormatFlagIsNonMixable = 0x40,
    kAudioFormatFlagsAreAllClear = 0x80000000,
    kLinearPCMFormatFlagIsFloat = kAudioFormatFlagIsFloat,
    kLinearPCMFormatFlagIsBigEndian = kAudioFormatFlagIsBigEndian,
    kLinearPCMFormatFlagIsSignedInteger = kAudioFormatFlagIsSignedInteger,
    kLinearPCMFormatFlagIsPacked = kAudioFormatFlagIsPacked,
    kLinearPCMFormatFlagIsAlignedHigh = kAudioFormatFlagIsAlignedHigh,
    kLinearPCMFormatFlagIsNonInterleaved = kAudioFormatFlagIsNonInterleaved,
    kLinearPCMFormatFlagIsNonMixable = kAudioFormatFlagIsNonMixable,
    kLinearPCMFormatFlagsSampleFractionShift = 0x7,
    kLinearPCMFormatFlagsSampleFractionMask = (0x3F << kLinearPCMFormatFlagsSampleFractionShift),
    kLinearPCMFormatFlagsAreAllClear = kAudioFormatFlagsAreAllClear
};

enum {
    kAudioFormatFlagsNativeEndian = 0,
    kAudioFormatFlagsCanonical = kAudioFormatFlagIsSignedInteger | kAudioFormatFlagsNativeEndian | kAudioFormatFlagIsPacked,
    kAudioFormatFlagsAudioUnitCanonical = kAudioFormatFlagIsSignedInteger | kAudioFormatFlagsNativeEndian | kAudioFormatFlagIsPacked |
                                          kAudioFormatFlagIsNonInterleaved |
                                          (kAudioUnitSampleFractionBits << kLinearPCMFormatFlagsSampleFractionShift),
    kAudioFormatFlagsNativeFloatPacked = kAudioFormatFlagIsFloat | kAudioFormatFlagsNativeEndian | kAudioFormatFlagIsPacked
};

typedef struct {
    SInt64 mStartOffset;
    UInt32 mVariableFramesInPacket;
    UInt32 mDataByteSize;
} AudioStreamPacketDescription;

typedef struct {
    SInt16 mSubframes;
    SInt16 mSubframeDivisor;
    UInt32 mCounter;
    UInt32 mType;
    UInt32 mFlags;
    SInt16 mHours;
    SInt16 mMinutes;
    SInt16 mSeconds;
    SInt16 mFrames;
} SMPTETime;

typedef struct {
    Float64 mSampleTime;
    UInt64 mHostTime;
    Float64 mRateScalar;
    UInt64 mWordClockTime;
    SMPTETime mSMPTETime;
    UInt32 mFlags;
    UInt32 mReserved;
} AudioTimeStamp;

#define TestAudioFormatNativeEndian(f) \
    ((f.mFormatID == kAudioFormatLinearPCM) && ((f.mFormatFlags & kAudioFormatFlagIsBigEndian) == kAudioFormatFlagsNativeEndian))

#endif /* _COREAUDIOTYPES_H_ */
