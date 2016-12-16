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

#include <COMIncludes.h>
#import <wrl\client.h>
#import <wrl\wrappers\corewrappers.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mferror.h>
#include <wmcodecdsp.h>
#include <COMIncludes_End.h>

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

struct OpaqueAudioConverter {
    IMFTransform* transform;
    float sizeChangeMultiplier;
};

static const wchar_t* TAG = L"AudioConverter";

/**
 @Status Caveat: AudioConverter supported only for conversions through AudioConverterConvertBuffer.
                 Returns kAudioConverterErr_UnspecifiedError on failure and noErr (0) on success. Other return types not supported.
 @Notes
*/
OSStatus AudioConverterDispose(AudioConverterRef inAudioConverter) {
    HRESULT status;

    status = MFShutdown();
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"MFShutdown Failed");
        return kAudioConverterErr_UnspecifiedError;
    }

    CoUninitialize();
    delete inAudioConverter;

    return noErr;
}

void _setMFProperties(const AudioStreamBasicDescription* format, IMFMediaType** mediaType) {
    IMFMediaType* tempMediaType = nullptr;
    MFCreateMediaType(&tempMediaType);

    tempMediaType->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Audio);

    if (format->mFormatFlags & kAudioFormatFlagIsFloat) {
        tempMediaType->SetGUID(MF_MT_SUBTYPE, MFAudioFormat_Float);
    } else {
        tempMediaType->SetGUID(MF_MT_SUBTYPE, MFAudioFormat_PCM);
    }

    tempMediaType->SetUINT32(MF_MT_AUDIO_NUM_CHANNELS, format->mChannelsPerFrame);
    tempMediaType->SetUINT32(MF_MT_AUDIO_SAMPLES_PER_SECOND, format->mSampleRate);
    tempMediaType->SetUINT32(MF_MT_AUDIO_BLOCK_ALIGNMENT, format->mBytesPerFrame);
    tempMediaType->SetUINT32(MF_MT_AUDIO_AVG_BYTES_PER_SECOND, format->mSampleRate * format->mBytesPerFrame);
    tempMediaType->SetUINT32(MF_MT_AUDIO_BITS_PER_SAMPLE, format->mBitsPerChannel);
    tempMediaType->SetUINT32(MF_MT_ALL_SAMPLES_INDEPENDENT, TRUE);

    *mediaType = tempMediaType;
}

/**
@Status Caveat: AudioConverter supported only for conversions through AudioConverterConvertBuffer.
                Only Linear PCM formats are supported with 1 Frame per Packet and equal source & destination Channels per Frame.
                Returns kAudioConverterErr_UnspecifiedError on failure and noErr (0) on success. Other return types not supported.
*/
OSStatus AudioConverterNew(const AudioStreamBasicDescription* inSourceFormat,
                           const AudioStreamBasicDescription* inDestinationFormat,
                           AudioConverterRef _Nullable* outAudioConverter) {
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

    HRESULT status;

    status = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"COM Initialization Failed");
        return kAudioConverterErr_UnspecifiedError;
    }

    status = MFStartup(MF_VERSION, MFSTARTUP_NOSOCKET);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Media Foundation Initialization Failed");
        return kAudioConverterErr_UnspecifiedError;
    }

    IUnknown* spTransformUnk;

    status = CoCreateInstance(CLSID_AudioResamplerMediaObject, nullptr, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&spTransformUnk);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Audio Resampler Initialization Failed");
        spTransformUnk->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    AudioConverterRef outConverter = new OpaqueAudioConverter;
    outConverter->transform = nullptr;

    status = spTransformUnk->QueryInterface(IID_PPV_ARGS(&outConverter->transform));
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Transform Initialization Failed");
        delete outConverter;
        spTransformUnk->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    IMFMediaType* sourceMediaType = nullptr;
    _setMFProperties(inSourceFormat, &sourceMediaType);
    status = outConverter->transform->SetInputType(0, sourceMediaType, 0);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"MFTransform InputStream Failed");
        delete outConverter;
        spTransformUnk->Release();
        sourceMediaType->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    IMFMediaType* destinationMediaType = nullptr;
    _setMFProperties(inDestinationFormat, &destinationMediaType);
    status = outConverter->transform->SetOutputType(0, destinationMediaType, 0);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"MFTransform OutputStream Failed");
        delete outConverter;
        spTransformUnk->Release();
        sourceMediaType->Release();
        destinationMediaType->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    outConverter->sizeChangeMultiplier = (inDestinationFormat->mSampleRate * inDestinationFormat->mBytesPerFrame) /
                                         (inSourceFormat->mSampleRate * inSourceFormat->mBytesPerFrame);

    status = outConverter->transform->ProcessMessage(MFT_MESSAGE_COMMAND_FLUSH, NULL);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"MFTransform Flush Failed");
        delete outConverter;
        spTransformUnk->Release();
        sourceMediaType->Release();
        destinationMediaType->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    status = outConverter->transform->ProcessMessage(MFT_MESSAGE_NOTIFY_BEGIN_STREAMING, NULL);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"MFTransform Begin Streaming Failed");
        delete outConverter;
        spTransformUnk->Release();
        sourceMediaType->Release();
        destinationMediaType->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    status = outConverter->transform->ProcessMessage(MFT_MESSAGE_NOTIFY_START_OF_STREAM, NULL);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"MFTransform Start Streaming Failed");
        delete outConverter;
        spTransformUnk->Release();
        sourceMediaType->Release();
        destinationMediaType->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    *outAudioConverter = outConverter;
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
 @Status Caveat: Returns kAudioConverterErr_UnspecifiedError, kAudioConverterErr_InvalidInputSize or
                 kAudioConverterErr_InvalidOutputSize on failure and noErr (0) on success. Other return types not supported.
 @Notes
*/
OSStatus AudioConverterConvertBuffer(
    AudioConverterRef inAudioConverter, UInt32 inInputDataSize, const void* inInputData, UInt32* ioOutputDataSize, void* outOutputData) {
    if (inAudioConverter == nullptr) {
        return kAudioConverterErr_UnspecifiedError;
    }

    if (inInputData == nullptr || inInputDataSize == 0) {
        return kAudioConverterErr_InvalidInputSize;
    }

    if (outOutputData == nullptr || ioOutputDataSize == 0 ||
        *ioOutputDataSize < ceil(float(inInputDataSize) * inAudioConverter->sizeChangeMultiplier)) {
        return kAudioConverterErr_InvalidOutputSize;
    }

    HRESULT status;
    IMFMediaBuffer* mediaBufferIn = nullptr;
    status = MFCreateMemoryBuffer(inInputDataSize, &mediaBufferIn);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Temp buffer creation failed");
        mediaBufferIn->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    BYTE* byteBufferIn = nullptr;
    status = mediaBufferIn->Lock(&byteBufferIn, nullptr, nullptr);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Buffer Lock failed");
        mediaBufferIn->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    memcpy(byteBufferIn, inInputData, inInputDataSize);
    status = mediaBufferIn->Unlock();
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Buffer Unlock failed");
        mediaBufferIn->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    status = mediaBufferIn->SetCurrentLength(inInputDataSize);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Set Length failed");
        mediaBufferIn->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    IMFSample* sampleIn = nullptr;
    status = MFCreateSample(&sampleIn);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"MFSample creation failed");
        mediaBufferIn->Release();
        sampleIn->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    status = sampleIn->AddBuffer(mediaBufferIn);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Buffer Addition failed");
        mediaBufferIn->Release();
        sampleIn->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    status = inAudioConverter->transform->ProcessInput(0, sampleIn, 0);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Input processing failed");
        mediaBufferIn->Release();
        sampleIn->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    IMFSample* sampleOut = NULL;
    // Create the output sample
    status = MFCreateSample(&sampleOut);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Output sample creation failed");
        mediaBufferIn->Release();
        sampleIn->Release();
        sampleOut->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    IMFMediaBuffer* bufferOut = NULL;
    // create a buffer for the output sample
    status = MFCreateMemoryBuffer(*ioOutputDataSize, &bufferOut);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Output buffer creation failed");
        mediaBufferIn->Release();
        sampleIn->Release();
        sampleOut->Release();
        bufferOut->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    // Add the output buffer
    status = sampleOut->AddBuffer(bufferOut);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Adding output buffer failed");
        mediaBufferIn->Release();
        sampleIn->Release();
        bufferOut->Release();
        sampleOut->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    DWORD inputID; // Input stream ID.
    DWORD outputID; // Output stream ID.
    status = inAudioConverter->transform->GetStreamIDs(1, &inputID, 1, &outputID);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Getting StreamIDs failed");
        mediaBufferIn->Release();
        sampleIn->Release();
        bufferOut->Release();
        sampleOut->Release();
        return kAudioConverterErr_UnspecifiedError;
    }

    // Starting the counter for number of bytes written to "outOutputData"
    *ioOutputDataSize = 0;
    bool drainFlag = false;
    MFT_OUTPUT_DATA_BUFFER dataBuffer;
    dataBuffer.pSample = sampleOut;
    dataBuffer.dwStreamID = outputID;
    DWORD outputStatus;

    for (;;) {
        status = inAudioConverter->transform->ProcessOutput(0, 1, &dataBuffer, &outputStatus);

        // State 0: All of the Input data has been processed. There may still be some Output data yet to be processed.
        if (status == MF_E_TRANSFORM_NEED_MORE_INPUT && drainFlag == false) {
            status = inAudioConverter->transform->ProcessMessage(MFT_MESSAGE_NOTIFY_END_OF_STREAM, NULL);
            if (!SUCCEEDED(status)) {
                NSTraceInfo(TAG, @"End Stream notification failed");
                mediaBufferIn->Release();
                sampleIn->Release();
                bufferOut->Release();
                sampleOut->Release();
                return kAudioConverterErr_UnspecifiedError;
            }

            status = inAudioConverter->transform->ProcessMessage(MFT_MESSAGE_COMMAND_DRAIN, NULL);
            if (!SUCCEEDED(status)) {
                NSTraceInfo(TAG, @"Drain notification failed");
                mediaBufferIn->Release();
                sampleIn->Release();
                bufferOut->Release();
                sampleOut->Release();
                return kAudioConverterErr_UnspecifiedError;
            }

            drainFlag = true;
            continue;
        }

        // State 1: The remaining Output data has been processed.
        if (status == MF_E_TRANSFORM_NEED_MORE_INPUT && drainFlag == true) {
            status = inAudioConverter->transform->ProcessMessage(MFT_MESSAGE_NOTIFY_END_STREAMING, NULL);
            if (!SUCCEEDED(status)) {
                NSTraceInfo(TAG, @"Nearing-End Stream notification failed");
                mediaBufferIn->Release();
                sampleIn->Release();
                bufferOut->Release();
                sampleOut->Release();
                return kAudioConverterErr_UnspecifiedError;
            }

            break;
        }

        IMFMediaBuffer* mediaBufferOut;
        status = sampleOut->ConvertToContiguousBuffer(&mediaBufferOut);
        if (!SUCCEEDED(status)) {
            NSTraceInfo(TAG, @"Buffer conversion failed");
            mediaBufferIn->Release();
            sampleIn->Release();
            bufferOut->Release();
            sampleOut->Release();
            mediaBufferOut->Release();
            return kAudioConverterErr_UnspecifiedError;
        }

        DWORD outputBytes = 0;
        mediaBufferOut->GetCurrentLength(&outputBytes);

        BYTE* outputByteBuffer = nullptr;
        status = mediaBufferOut->Lock(&outputByteBuffer, nullptr, nullptr);
        if (!SUCCEEDED(status)) {
            NSTraceInfo(TAG, @"Output Buffer Lock failed");
            mediaBufferIn->Release();
            sampleIn->Release();
            bufferOut->Release();
            sampleOut->Release();
            mediaBufferOut->Release();
            return kAudioConverterErr_UnspecifiedError;
        }

        memcpy(static_cast<BYTE*>(outOutputData) + *ioOutputDataSize, outputByteBuffer, outputBytes);
        *ioOutputDataSize += outputBytes;

        status = mediaBufferOut->Unlock();
        if (!SUCCEEDED(status)) {
            NSTraceInfo(TAG, @"Output Buffer Unlock failed");
            mediaBufferIn->Release();
            sampleIn->Release();
            bufferOut->Release();
            sampleOut->Release();
            mediaBufferOut->Release();
            return kAudioConverterErr_UnspecifiedError;
        }

        mediaBufferOut->Release();
    }

    mediaBufferIn->Release();
    sampleIn->Release();
    bufferOut->Release();
    sampleOut->Release();

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