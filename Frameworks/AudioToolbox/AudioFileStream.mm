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

#import <AudioToolbox/AudioFileStream.h>
#import <StubReturn.h>

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileStreamOpen(void* inClientData,
                             AudioFileStream_PropertyListenerProc inPropertyListenerProc,
                             AudioFileStream_PacketsProc inPacketsProc,
                             AudioFileTypeID inFileTypeHint,
                             AudioFileStreamID _Nullable* outAudioFileStream) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileStreamParseBytes(AudioFileStreamID inAudioFileStream,
                                   UInt32 inDataByteSize,
                                   const void* inData,
                                   AudioFileStreamParseFlags inFlags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileStreamSeek(AudioFileStreamID inAudioFileStream,
                             SInt64 inPacketOffset,
                             SInt64* outDataByteOffset,
                             AudioFileStreamSeekFlags* ioFlags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileStreamGetPropertyInfo(AudioFileStreamID inAudioFileStream,
                                        AudioFileStreamPropertyID inPropertyID,
                                        UInt32* outPropertyDataSize,
                                        Boolean* outWritable) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileStreamGetProperty(AudioFileStreamID inAudioFileStream,
                                    AudioFileStreamPropertyID inPropertyID,
                                    UInt32* ioPropertyDataSize,
                                    void* outPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileStreamSetProperty(AudioFileStreamID inAudioFileStream,
                                    AudioFileStreamPropertyID inPropertyID,
                                    UInt32 inPropertyDataSize,
                                    const void* inPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFileStreamClose(AudioFileStreamID inAudioFileStream) {
    UNIMPLEMENTED();
    return StubReturn();
}