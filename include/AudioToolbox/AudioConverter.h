//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

enum {
    kAudioConverterPropertyMinimumInputBufferSize = 'mibs',
    kAudioConverterPropertyMinimumOutputBufferSize = 'mobs',
    kAudioConverterPropertyMaximumInputBufferSize = 'xibs',
    kAudioConverterPropertyMaximumInputPacketSize = 'xips',
    kAudioConverterPropertyMaximumOutputPacketSize = 'xops',
    kAudioConverterPropertyCalculateInputBufferSize = 'cibs',
    kAudioConverterPropertyCalculateOutputBufferSize = 'cobs',
    kAudioConverterPropertyInputCodecParameters = 'icdp',
    kAudioConverterPropertyOutputCodecParameters = 'ocdp',
    kAudioConverterSampleRateConverterAlgorithm = 'srci',
    kAudioConverterSampleRateConverterComplexity = 'srca',
    kAudioConverterSampleRateConverterQuality = 'srcq',
    kAudioConverterSampleRateConverterInitialPhase = 'srcp',
    kAudioConverterCodecQuality = 'cdqu',
    kAudioConverterPrimeMethod = 'prmm',
    kAudioConverterPrimeInfo = 'prim',
    kAudioConverterChannelMap = 'chmp',
    kAudioConverterDecompressionMagicCookie = 'dmgc',
    kAudioConverterCompressionMagicCookie = 'cmgc',
    kAudioConverterEncodeBitRate = 'brat',
    kAudioConverterEncodeAdjustableSampleRate = 'ajsr',
    kAudioConverterInputChannelLayout = 'icl ',
    kAudioConverterOutputChannelLayout = 'ocl ',
    kAudioConverterApplicableEncodeBitRates = 'aebr',
    kAudioConverterAvailableEncodeBitRates = 'vebr',
    kAudioConverterApplicableEncodeSampleRates = 'aesr',
    kAudioConverterAvailableEncodeSampleRates = 'vesr',
    kAudioConverterAvailableEncodeChannelLayoutTags = 'aecl',
    kAudioConverterCurrentOutputStreamDescription = 'acod',
    kAudioConverterCurrentInputStreamDescription = 'acid',
    kAudioConverterPropertySettings = 'acps',
    kAudioConverterPropertyBitDepthHint = 'acbd',
    kAudioConverterPropertyFormatList = 'flst',
    kAudioConverterPropertyCanResumeFromInterruption = 'crfi'
};

enum { kConverterPrimeMethod_Pre = 0, kConverterPrimeMethod_Normal = 1, kConverterPrimeMethod_None = 2 };

enum {
    kAudioConverterQuality_Max = 0x7F,
    kAudioConverterQuality_High = 0x60,
    kAudioConverterQuality_Medium = 0x40,
    kAudioConverterQuality_Low = 0x20,
    kAudioConverterQuality_Min = 0
};

enum {
    kAudioConverterSampleRateConverterComplexity_Linear = 'line',
    kAudioConverterSampleRateConverterComplexity_Normal = 'norm',
    kAudioConverterSampleRateConverterComplexity_Mastering = 'bats',
};

enum {
    kAudioConverterErr_FormatNotSupported = 'fmt?',
    kAudioConverterErr_OperationNotSupported = 0x6F703F3F,
    kAudioConverterErr_PropertyNotSupported = 'prop',
    kAudioConverterErr_InvalidInputSize = 'insz',
    kAudioConverterErr_InvalidOutputSize = 'otsz',
    kAudioConverterErr_UnspecifiedError = 'what',
    kAudioConverterErr_BadPropertySizeError = '!siz',
    kAudioConverterErr_RequiresPacketDescriptionsError = '!pkd',
    kAudioConverterErr_InputSampleRateOutOfRange = '!isr',
    kAudioConverterErr_OutputSampleRateOutOfRange = '!osr',
    kAudioConverterErr_HardwareInUse = 'hwiu',
    kAudioConverterErr_NoHardwarePermission = 'perm'
};

struct AudioConverterPrimeInfo {
    UInt32 leadingFrames;
    UInt32 trailingFrames;
};
typedef struct OpaqueAudioConverter* AudioConverterRef;
typedef UInt32 AudioConverterPropertyID;
typedef OSStatus (*AudioConverterComplexInputDataProc)(AudioConverterRef inAudioConverter,
                                                       UInt32* ioNumberDataPackets,
                                                       AudioBufferList* ioData,
                                                       AudioStreamPacketDescription** outDataPacketDescription,
                                                       void* inUserData);
typedef OSStatus (*AudioConverterInputDataProc)(AudioConverterRef inAudioConverter, UInt32* ioDataSize, void** outData, void* inUserData);
typedef struct AudioConverterPrimeInfo AudioConverterPrimeInfo;

AUDIOTOOLBOX_EXPORT OSStatus AudioConverterDispose(AudioConverterRef inAudioConverter);
AUDIOTOOLBOX_EXPORT OSStatus AudioConverterNew(const AudioStreamBasicDescription* inSourceFormat,
                                               const AudioStreamBasicDescription* inDestinationFormat,
                                               AudioConverterRef _Nullable* outAudioConverter);
AUDIOTOOLBOX_EXPORT OSStatus AudioConverterNewSpecific(const AudioStreamBasicDescription* inSourceFormat,
                                                       const AudioStreamBasicDescription* inDestinationFormat,
                                                       UInt32 inNumberClassDescriptions,
                                                       const AudioClassDescription* inClassDescriptions,
                                                       AudioConverterRef _Nullable* outAudioConverter) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioConverterReset(AudioConverterRef inAudioConverter) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioConverterGetProperty(AudioConverterRef inAudioConverter,
                                                       AudioConverterPropertyID inPropertyID,
                                                       UInt32* ioPropertyDataSize,
                                                       void* outPropertyData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioConverterGetPropertyInfo(AudioConverterRef inAudioConverter,
                                                           AudioConverterPropertyID inPropertyID,
                                                           UInt32* outSize,
                                                           Boolean* outWritable) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioConverterSetProperty(AudioConverterRef inAudioConverter,
                                                       AudioConverterPropertyID inPropertyID,
                                                       UInt32 inPropertyDataSize,
                                                       const void* inPropertyData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioConverterConvertBuffer(AudioConverterRef inAudioConverter,
                                                         UInt32 inInputDataSize,
                                                         const void* inInputData,
                                                         UInt32* ioOutputDataSize,
                                                         void* outOutputData);
AUDIOTOOLBOX_EXPORT OSStatus AudioConverterFillComplexBuffer(AudioConverterRef inAudioConverter,
                                                             AudioConverterComplexInputDataProc inInputDataProc,
                                                             void* inInputDataProcUserData,
                                                             UInt32* ioOutputDataPacketSize,
                                                             AudioBufferList* outOutputData,
                                                             AudioStreamPacketDescription* outPacketDescription) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioConverterConvertComplexBuffer(AudioConverterRef inAudioConverter,
                                                                UInt32 inNumberPCMFrames,
                                                                const AudioBufferList* inInputData,
                                                                AudioBufferList* outOutputData) STUB_METHOD;