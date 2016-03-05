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

#import <AudioToolbox/AudioConverter.h>
#import <StubReturn.h>

/**
 @Status Stub
 @Notes
*/
OSStatus AudioConverterDispose(AudioConverterRef inAudioConverter) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
*/
DWORD AudioConverterNew(AudioStreamBasicDescription* in, AudioStreamBasicDescription* out, DWORD* handle) {
    *handle = 1234;
    return 0;
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
 @Status Stub
 @Notes
*/
OSStatus AudioConverterConvertBuffer(
    AudioConverterRef inAudioConverter, UInt32 inInputDataSize, const void* inInputData, UInt32* ioOutputDataSize, void* outOutputData) {
    UNIMPLEMENTED();
    return StubReturn();
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