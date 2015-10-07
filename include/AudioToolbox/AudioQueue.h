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

#ifndef _AUDIOQUEUE_H_
#define _AUDIOQUEUE_H_

#import <CoreAudio/CoreAudioTypes.h>
#import <CoreFoundation/CFRunLoop.h>
#import <StarboardExport.h>

typedef struct OpaqueAudioQueue *AudioQueueRef;
typedef struct OpaqueAudioQueueTimeline *AudioQueueTimelineRef;
typedef Float32 AudioQueueParameterValue;

typedef struct AudioQueueBuffer {
    const UInt32                 mAudioDataBytesCapacity;
    void                         *const mAudioData;
    UInt32                       mAudioDataByteSize;
    void                         *mUserData;
    const UInt32                 mPacketDescriptionCapacity;
    AudioStreamPacketDescription *const mPacketDescriptions;
    UInt32                       mPacketDescriptionCount;
} AudioQueueBuffer;
typedef AudioQueueBuffer *AudioQueueBufferRef;

enum {
    kAudioQueueProperty_IsRunning               = 'aqrn',
    kAudioQueueDeviceProperty_SampleRate        = 'aqsr',
    kAudioQueueDeviceProperty_NumberChannels    = 'aqdc',
    kAudioQueueProperty_CurrentDevice           = 'aqcd',
    kAudioQueueProperty_MagicCookie             = 'aqmc',
    kAudioQueueProperty_MaximumOutputPacketSize = 'xops',
    kAudioQueueProperty_StreamDescription       = 'aqft',
    kAudioQueueProperty_ChannelLayout           = 'aqcl',
    kAudioQueueProperty_EnableLevelMetering     = 'aqme',
    kAudioQueueProperty_CurrentLevelMeter       = 'aqmv',
    kAudioQueueProperty_CurrentLevelMeterDB     = 'aqmd',
    kAudioQueueProperty_DecodeBufferSizeFrames  = 'dcbf',
    kAudioQueueProperty_ConverterError          = 'qcve'
};
typedef uint32_t AudioQueuePropertyID;

typedef void (*AudioQueueOutputCallback) (void *inUserData, AudioQueueRef inAQ, AudioQueueBufferRef inBuffer);
typedef void (*AudioQueuePropertyListenerProc) (void *inUserData, AudioQueueRef inAQ, AudioQueuePropertyID inID);

enum {
    kAudioQueueParam_Volume = 1,
    kAudioQueueParam_VolumeRampTime = 4,
    kAudioQueueParam_Pan = 13
};
typedef uint32_t AudioQueueParameterID;

SB_EXPORT OSStatus AudioQueueSetParameter(AudioQueueRef inAQ, AudioQueueParameterID inParamID, AudioQueueParameterValue inValue);
SB_EXPORT OSStatus AudioQueueStop(AudioQueueRef inAQ, Boolean inImmediate);
SB_EXPORT OSStatus AudioQueuePause(AudioQueueRef inAQ);
SB_EXPORT OSStatus AudioQueueDispose(AudioQueueRef inAQ, Boolean inImmediate);
SB_EXPORT OSStatus AudioQueueStart(AudioQueueRef inAQ, const AudioTimeStamp *inStartTime);
SB_EXPORT OSStatus AudioQueueFlush(AudioQueueRef inAQ);
SB_EXPORT OSStatus AudioQueueGetCurrentTime(AudioQueueRef inAQ, AudioQueueTimelineRef inTimeline, AudioTimeStamp *outTimeStamp, Boolean *outTimelineDiscontinuity);
SB_EXPORT OSStatus AudioQueueEnqueueBuffer(AudioQueueRef inAQ, AudioQueueBufferRef inBuffer, UInt32 inNumPacketDescs, const AudioStreamPacketDescription *inPacketDescs);
SB_EXPORT OSStatus AudioQueueNewOutput(const AudioStreamBasicDescription *inFormat, AudioQueueOutputCallback inCallbackProc, void *inUserData, CFRunLoopRef inCallbackRunLoop, CFStringRef inCallbackRunLoopMode, UInt32 inFlags, AudioQueueRef *outAQ);
SB_EXPORT OSStatus AudioQueueAllocateBuffer(AudioQueueRef inAQ, UInt32 inBufferByteSize, AudioQueueBufferRef *outBuffer);
SB_EXPORT OSStatus AudioQueueAddPropertyListener(AudioQueueRef inAQ, AudioQueuePropertyID inID, AudioQueuePropertyListenerProc inProc, void *inUserData);
SB_EXPORT OSStatus AudioQueueSetProperty(AudioQueueRef inAQ, AudioQueuePropertyID inID, const void *inData, UInt32 inDataSize);

#endif /* _AUDIOQUEUE_H_ */