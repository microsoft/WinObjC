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

#import <AudioToolbox/AudioConverter.h>
#import <StubReturn.h>
#import <NSBundleInternal.h>
#import <NSLogging.h>
#import "AssertARCEnabled.h"

static const wchar_t* TAG = L"AudioConverter";

#import <AudioToolbox/AudioConverterInternal.h>


@implementation AudioConverter
- (instancetype)initWithSourceFormat:(const AudioStreamBasicDescription*)srcFormat
                   destinationFormat:(const AudioStreamBasicDescription*)destFormat {
    if (self = [super init]) {
        ComPtr<IUnknown> spTransformUnk;

        RETURN_NIL_IF_FAILED(
            CoCreateInstance(CLSID_AudioResamplerMediaObject, nullptr, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&spTransformUnk));

        RETURN_NIL_IF_FAILED(spTransformUnk.As(&_transform));

        _sizeChangeMultiplier =
            (destFormat->mSampleRate * destFormat->mBytesPerFrame) / (srcFormat->mSampleRate * srcFormat->mBytesPerFrame);
    }

    return self;
}

- (ComPtr<IMFTransform>)getTransform {
    return _transform;
}

- (float)getSizeChangeMultiplier {
    return _sizeChangeMultiplier;
}
@end

/**
 @Status Caveat
 @Notes AudioConverter supported only for conversions through AudioConverterConvertBuffer. 
        Returns kAudioConverterErr_UnspecifiedError on failure and noErr (0) on success. Other return types not supported.
*/
OSStatus AudioConverterDispose(AudioConverterRef inAudioConverter) {
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(MFShutdown(), @"MFShutdown Failed");
    CFBridgingRelease(inAudioConverter);
    return noErr;
}

OSStatus _setMFProperties(const AudioStreamBasicDescription* format, IMFMediaType** mediaType) {
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(MFCreateMediaType(mediaType), @"MFCreateMediaType failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG((*mediaType)->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Audio), @"Setting the major type failed");

    if (format->mFormatFlags & kAudioFormatFlagIsFloat) {
        RETURN_AUDIOERR_IF_FAILED_WITH_MSG((*mediaType)->SetGUID(MF_MT_SUBTYPE, MFAudioFormat_Float), @"Setting the subtype failed");
    } else {
        RETURN_AUDIOERR_IF_FAILED_WITH_MSG((*mediaType)->SetGUID(MF_MT_SUBTYPE, MFAudioFormat_PCM), @"Setting the subtype failed");
    }

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG((*mediaType)->SetUINT32(MF_MT_AUDIO_NUM_CHANNELS, format->mChannelsPerFrame),
                                       @"Setting the number of audio channels failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG((*mediaType)->SetUINT32(MF_MT_AUDIO_SAMPLES_PER_SECOND, format->mSampleRate),
                                       @"Setting the number of audio samples per second failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG((*mediaType)->SetUINT32(MF_MT_AUDIO_BLOCK_ALIGNMENT, format->mBytesPerFrame),
                                       @"Setting the block alignment failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG((*mediaType)
                                           ->SetUINT32(MF_MT_AUDIO_AVG_BYTES_PER_SECOND, format->mSampleRate * format->mBytesPerFrame),
                                       @"Setting the average number of bytes per second failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG((*mediaType)->SetUINT32(MF_MT_AUDIO_BITS_PER_SAMPLE, format->mBitsPerChannel),
                                       @"Setting the number of bits per audio sample failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG((*mediaType)->SetUINT32(MF_MT_ALL_SAMPLES_INDEPENDENT, TRUE),
                                       @"Setting the audio sample independent flag failed");

    return noErr;
}

/**
@Status Caveat
@Notes AudioConverter supported only for conversions through AudioConverterConvertBuffer.
       Only Linear PCM formats are supported with 1 Frame per Packet and equal source & destination Channels per Frame.
       Returns kAudioConverterErr_UnspecifiedError on failure and noErr (0) on success. Other return types not supported.
*/
OSStatus AudioConverterNew(const AudioStreamBasicDescription* inSourceFormat,
                           const AudioStreamBasicDescription* inDestinationFormat,
                           AudioConverterRef _Nullable* outAudioConverter) {
    if (inSourceFormat == nullptr || inDestinationFormat == nullptr) {
        return kAudioConverterErr_UnspecifiedError;
    }

    if (inSourceFormat->mFormatID != kAudioFormatLinearPCM || inDestinationFormat->mFormatID != kAudioFormatLinearPCM) {
        UNIMPLEMENTED();
        return StubReturn();
    }

    if (inSourceFormat->mChannelsPerFrame != inDestinationFormat->mChannelsPerFrame) {
        UNIMPLEMENTED();
        return StubReturn();
    }

    if (inSourceFormat->mFramesPerPacket != 1 || inSourceFormat->mFramesPerPacket != inDestinationFormat->mFramesPerPacket) {
        UNIMPLEMENTED();
        return StubReturn();
    }

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(MFStartup(MF_VERSION, MFSTARTUP_NOSOCKET), @"MFStartup Failed");

    AudioConverter* outConverter = [[AudioConverter alloc] initWithSourceFormat:inSourceFormat destinationFormat:inDestinationFormat];

    ComPtr<IMFTransform> mediaTransform = [outConverter getTransform];

    ComPtr<IMFMediaType> sourceMediaType;
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(_setMFProperties(inSourceFormat, &sourceMediaType), @"Creating source mediatype Failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaTransform->SetInputType(0, sourceMediaType.Get(), 0), @"MFTransform InputStream Failed");

    ComPtr<IMFMediaType> destinationMediaType;
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(_setMFProperties(inDestinationFormat, &destinationMediaType),
                                       @"Creating destination mediatype Failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaTransform->SetOutputType(0, destinationMediaType.Get(), 0), @"MFTransform OutputStream Failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaTransform->ProcessMessage(MFT_MESSAGE_COMMAND_FLUSH, NULL), @"MFTransform Flush Failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaTransform->ProcessMessage(MFT_MESSAGE_NOTIFY_BEGIN_STREAMING, NULL),
                                       @"MFTransform Begin Streaming Failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaTransform->ProcessMessage(MFT_MESSAGE_NOTIFY_START_OF_STREAM, NULL),
                                       @"MFTransform Start Streaming Failed");

    *outAudioConverter = (AudioConverterRef)CFBridgingRetain(outConverter);
    return noErr;
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioConverterNewSpecific(const AudioStreamBasicDescription* inSourceFormat,
                                   const AudioStreamBasicDescription* inDestinationFormat,
                                   UInt32 inNumberClassDescriptions,
                                   const AudioClassDescription* inClassDescriptions,
                                   AudioConverterRef _Nullable* outAudioConverter) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioConverterReset(AudioConverterRef inAudioConverter) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioConverterGetProperty(AudioConverterRef inAudioConverter,
                                   AudioConverterPropertyID inPropertyID,
                                   UInt32* ioPropertyDataSize,
                                   void* outPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioConverterGetPropertyInfo(AudioConverterRef inAudioConverter,
                                       AudioConverterPropertyID inPropertyID,
                                       UInt32* outSize,
                                       Boolean* outWritable) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioConverterSetProperty(AudioConverterRef inAudioConverter,
                                   AudioConverterPropertyID inPropertyID,
                                   UInt32 inPropertyDataSize,
                                   const void* inPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Returns kAudioConverterErr_UnspecifiedError, kAudioConverterErr_InvalidInputSize or
        kAudioConverterErr_InvalidOutputSize on failure and noErr (0) on success. Other return types not supported.
*/
OSStatus AudioConverterConvertBuffer(
    AudioConverterRef inAudioConverter, UInt32 inInputDataSize, const void* inInputData, UInt32* ioOutputDataSize, void* outOutputData) {
    if (inAudioConverter == nullptr) {
        return kAudioConverterErr_UnspecifiedError;
    }

    if (inInputData == nullptr || inInputDataSize == 0) {
        return kAudioConverterErr_InvalidInputSize;
    }

    float multiplier = [(__bridge AudioConverter*)inAudioConverter getSizeChangeMultiplier];
    if (outOutputData == nullptr || ioOutputDataSize == 0 || *ioOutputDataSize < ceil(float(inInputDataSize) * multiplier)) {
        return kAudioConverterErr_InvalidOutputSize;
    }

    ComPtr<IMFMediaBuffer> mediaBufferIn = nullptr;
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(MFCreateMemoryBuffer(inInputDataSize, &mediaBufferIn), @"Temp buffer creation failed");

    BYTE* byteBufferIn = nullptr;
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaBufferIn->Lock(&byteBufferIn, nullptr, nullptr), @"Buffer Lock failed");

    memcpy(byteBufferIn, inInputData, inInputDataSize);
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaBufferIn->Unlock(), @"Buffer Unlock failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaBufferIn->SetCurrentLength(inInputDataSize), @"Set Length failed");

    ComPtr<IMFSample> sampleIn = nullptr;
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(MFCreateSample(&sampleIn), @"MFSample creation failed");

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(sampleIn->AddBuffer(mediaBufferIn.Get()), @"Buffer Addition failed");

    ComPtr<IMFTransform> mediaTransform = [(__bridge AudioConverter*)inAudioConverter getTransform];

    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaTransform->ProcessInput(0, sampleIn.Get(), 0), @"Input processing failed");

    // Create the output sample
    ComPtr<IMFSample> sampleOut = NULL;
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(MFCreateSample(&sampleOut), @"Output sample creation failed");

    // Create a buffer for the output sample
    ComPtr<IMFMediaBuffer> bufferOut = NULL;
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(MFCreateMemoryBuffer(*ioOutputDataSize, &bufferOut), @"Output buffer creation failed");

    // Add the output buffer
    RETURN_AUDIOERR_IF_FAILED_WITH_MSG(sampleOut->AddBuffer(bufferOut.Get()), @"Adding output buffer failed");

    // Starting the counter for number of bytes written to "outOutputData"
    *ioOutputDataSize = 0;
    bool drainFlag = false;
    MFT_OUTPUT_DATA_BUFFER dataBuffer;
    dataBuffer.pSample = sampleOut.Get();
    dataBuffer.dwStreamID = 0;
    dataBuffer.dwStatus = 0;
    dataBuffer.pEvents = NULL;
    DWORD outputStatus;

    for (;;) {
        HRESULT status = mediaTransform->ProcessOutput(0, 1, &dataBuffer, &outputStatus);

        // State 0: All of the Input data has been processed. There may still be some Output data yet to be processed.
        if (status == MF_E_TRANSFORM_NEED_MORE_INPUT && drainFlag == false) {
            RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaTransform->ProcessMessage(MFT_MESSAGE_NOTIFY_END_OF_STREAM, NULL),
                                               @"End Stream notification failed");

            RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaTransform->ProcessMessage(MFT_MESSAGE_COMMAND_DRAIN, NULL),
                                               @"Drain notification failed");

            drainFlag = true;
            continue;
        }

        // State 1: The remaining Output data has been processed.
        if (status == MF_E_TRANSFORM_NEED_MORE_INPUT && drainFlag == true) {
            RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaTransform->ProcessMessage(MFT_MESSAGE_NOTIFY_END_STREAMING, NULL),
                                               @"Nearing-End Stream notification failed");
            break;
        }

        ComPtr<IMFMediaBuffer> mediaBufferOut;
        RETURN_AUDIOERR_IF_FAILED_WITH_MSG(sampleOut->ConvertToContiguousBuffer(&mediaBufferOut), @"Buffer conversion failed");

        DWORD outputBytes = 0;
        mediaBufferOut->GetCurrentLength(&outputBytes);

        BYTE* outputByteBuffer = nullptr;
        RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaBufferOut->Lock(&outputByteBuffer, nullptr, nullptr), @"Output Buffer Lock failed");

        memcpy(static_cast<BYTE*>(outOutputData) + *ioOutputDataSize, outputByteBuffer, outputBytes);
        *ioOutputDataSize += outputBytes;

        RETURN_AUDIOERR_IF_FAILED_WITH_MSG(mediaBufferOut->Unlock(), @"Output Buffer Unlock failed");
    }

    return noErr;
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioConverterFillComplexBuffer(AudioConverterRef inAudioConverter,
                                         AudioConverterComplexInputDataProc inInputDataProc,
                                         void* inInputDataProcUserData,
                                         UInt32* ioOutputDataPacketSize,
                                         AudioBufferList* outOutputData,
                                         AudioStreamPacketDescription* outPacketDescription) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioConverterConvertComplexBuffer(AudioConverterRef inAudioConverter,
                                            UInt32 inNumberPCMFrames,
                                            const AudioBufferList* inInputData,
                                            AudioBufferList* outOutputData) {
    UNIMPLEMENTED();
    return StubReturn();
}