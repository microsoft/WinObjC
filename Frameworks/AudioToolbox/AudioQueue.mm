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

#import <AudioToolbox/AudioQueue.h>
#import <StubReturn.h>

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueStart(AudioQueueRef inAQ, const AudioTimeStamp* inStartTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueuePrime(AudioQueueRef inAQ, UInt32 inNumberOfFramesToPrepare, UInt32* outNumberOfFramesPrepared) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueFlush(AudioQueueRef inAQ) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueStop(AudioQueueRef inAQ, Boolean inImmediate) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueuePause(AudioQueueRef inAQ) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueReset(AudioQueueRef inAQ) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueNewOutput(const AudioStreamBasicDescription* inFormat,
                             AudioQueueOutputCallback inCallbackProc,
                             void* inUserData,
                             CFRunLoopRef inCallbackRunLoop,
                             CFStringRef inCallbackRunLoopMode,
                             UInt32 inFlags,
                             AudioQueueRef _Nullable* outAQ) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueNewInput(const AudioStreamBasicDescription* inFormat,
                            AudioQueueInputCallback inCallbackProc,
                            void* inUserData,
                            CFRunLoopRef inCallbackRunLoop,
                            CFStringRef inCallbackRunLoopMode,
                            UInt32 inFlags,
                            AudioQueueRef _Nullable* outAQ) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueDispose(AudioQueueRef inAQ, Boolean inImmediate) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueAllocateBuffer(AudioQueueRef inAQ, UInt32 inBufferByteSize, AudioQueueBufferRef _Nullable* outBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueAllocateBufferWithPacketDescriptions(AudioQueueRef inAQ,
                                                        UInt32 inBufferByteSize,
                                                        UInt32 inNumberPacketDescriptions,
                                                        AudioQueueBufferRef _Nullable* outBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueFreeBuffer(AudioQueueRef inAQ, AudioQueueBufferRef inBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueEnqueueBuffer(AudioQueueRef inAQ,
                                 AudioQueueBufferRef inBuffer,
                                 UInt32 inNumPacketDescs,
                                 const AudioStreamPacketDescription* inPacketDescs) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueEnqueueBufferWithParameters(AudioQueueRef inAQ,
                                               AudioQueueBufferRef inBuffer,
                                               UInt32 inNumPacketDescs,
                                               const AudioStreamPacketDescription* inPacketDescs,
                                               UInt32 inTrimFramesAtStart,
                                               UInt32 inTrimFramesAtEnd,
                                               UInt32 inNumParamValues,
                                               const AudioQueueParameterEvent* inParamValues,
                                               const AudioTimeStamp* inStartTime,
                                               AudioTimeStamp* outActualStartTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueGetParameter(AudioQueueRef inAQ, AudioQueueParameterID inParamID, AudioQueueParameterValue* outValue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueSetParameter(AudioQueueRef inAQ, AudioQueueParameterID inParamID, AudioQueueParameterValue inValue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueGetProperty(AudioQueueRef inAQ, AudioQueuePropertyID inID, void* outData, UInt32* ioDataSize) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueSetProperty(AudioQueueRef inAQ, AudioQueuePropertyID inID, const void* inData, UInt32 inDataSize) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueGetPropertySize(AudioQueueRef inAQ, AudioQueuePropertyID inID, UInt32* outDataSize) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueAddPropertyListener(AudioQueueRef inAQ,
                                       AudioQueuePropertyID inID,
                                       AudioQueuePropertyListenerProc inProc,
                                       void* inUserData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueRemovePropertyListener(AudioQueueRef inAQ,
                                          AudioQueuePropertyID inID,
                                          AudioQueuePropertyListenerProc inProc,
                                          void* inUserData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueCreateTimeline(AudioQueueRef inAQ, AudioQueueTimelineRef _Nullable* outTimeline) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueDisposeTimeline(AudioQueueRef inAQ, AudioQueueTimelineRef inTimeline) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueDeviceGetCurrentTime(AudioQueueRef inAQ, AudioTimeStamp* outTimeStamp) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueDeviceGetNearestStartTime(AudioQueueRef inAQ, AudioTimeStamp* ioRequestedStartTime, UInt32 inFlags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueDeviceTranslateTime(AudioQueueRef inAQ, const AudioTimeStamp* inTime, AudioTimeStamp* outTime) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueGetCurrentTime(AudioQueueRef inAQ,
                                  AudioQueueTimelineRef inTimeline,
                                  AudioTimeStamp* outTimeStamp,
                                  Boolean* outTimelineDiscontinuity) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueSetOfflineRenderFormat(AudioQueueRef inAQ,
                                          const AudioStreamBasicDescription* inFormat,
                                          const AudioChannelLayout* inLayout) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioQueueOfflineRender(AudioQueueRef inAQ,
                                 const AudioTimeStamp* inTimestamp,
                                 AudioQueueBufferRef ioBuffer,
                                 UInt32 inNumberFrames) {
    UNIMPLEMENTED();
    return StubReturn();
}