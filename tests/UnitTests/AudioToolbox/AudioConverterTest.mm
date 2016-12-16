//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#include <TestFramework.h>
#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <StubReturn.h>
#import <NSBundleInternal.h>
#import <NSLogging.h>

// This is needed for getting mfapi.h to build
#ifndef OUT
#define OUT
#endif

#include <COMIncludes.h>
#import <wrl\client.h>
#import <wrl\wrappers\corewrappers.h>
#import <mfapi.h>
#include <mfidl.h>
#include <mferror.h>
#include <wmcodecdsp.h>
#include <COMIncludes_End.h>

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

@interface AudioConverter : NSObject
@property (atomic) ComPtr<IMFTransform> transform;
@property (atomic) float sizeChangeMultiplier;
- (float)getSizeChangeMultiplier;
@end

@implementation AudioConverter
- (ComPtr<IMFTransform>)getTransform {
    return _transform;
}

- (float)getSizeChangeMultiplier {
    return _sizeChangeMultiplier;
}
@end

static const wchar_t* TAG = L"AudioConverterTest";

#define RETURN_AUDIOERR_IF_FAILED_WITH_MSG(hr, msg) \
    if (FAILED(hr)) {                               \
        NSTraceInfo(TAG, @"%@", msg);               \
        return kAudioConverterErr_UnspecifiedError; \
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

TEST(AudioToolbox, AudioConverterTest) {
    AudioStreamBasicDescription inFormat;
    inFormat.mSampleRate = 44100;
    inFormat.mFormatID = kAudioFormatLinearPCM;
    inFormat.mFormatFlags = (kAudioFormatFlagIsPacked | kAudioFormatFlagIsSignedInteger);
    inFormat.mBytesPerPacket = 4;
    inFormat.mFramesPerPacket = 1;
    inFormat.mBytesPerFrame = 4;
    inFormat.mChannelsPerFrame = 2;
    inFormat.mBitsPerChannel = 16;
    inFormat.mReserved = 0;

    AudioStreamBasicDescription outFormat;
    outFormat.mSampleRate = 44100;
    outFormat.mFormatID = kAudioFormatLinearPCM;
    outFormat.mFormatFlags = (kAudioFormatFlagIsPacked | kAudioFormatFlagIsFloat);
    outFormat.mBytesPerPacket = 8;
    outFormat.mFramesPerPacket = 1;
    outFormat.mBytesPerFrame = 8;
    outFormat.mChannelsPerFrame = 2;
    outFormat.mBitsPerChannel = 32;
    outFormat.mReserved = 0;

    AudioConverterRef converter;
    OSStatus err = noErr;
    err = AudioConverterNew(&inFormat, &outFormat, &converter);
    ASSERT_EQ(err, 0);

    DWORD flag = MF_MEDIATYPE_EQUAL_FORMAT_USER_DATA;
    DWORD streamID = 0;
    ComPtr<IMFTransform> mediaTransform = [(__bridge AudioConverter*)converter getTransform];

    ComPtr<IMFMediaType> expectedInMediaType = nullptr;
    _setMFProperties(&inFormat, &expectedInMediaType);
    ComPtr<IMFMediaType> resInMediaType = nullptr;
    mediaTransform->GetInputCurrentType(streamID, &resInMediaType);
    HRESULT hr = resInMediaType->IsEqual(expectedInMediaType.Get(), &flag);
    HRESULT hrExpected = S_OK;
    ASSERT_EQ(hr, hrExpected);

    ComPtr<IMFMediaType> expectedOutMediaType = nullptr;
    _setMFProperties(&outFormat, &expectedOutMediaType);
    ComPtr<IMFMediaType> resOutMediaType = nullptr;
    mediaTransform->GetOutputCurrentType(streamID, &resOutMediaType);
    hr = resOutMediaType->IsEqual(expectedOutMediaType.Get(), &flag);
    ASSERT_EQ(hr, hrExpected);

    err = AudioConverterDispose(converter);
    ASSERT_EQ(err, 0);
}