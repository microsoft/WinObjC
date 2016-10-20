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

#include "Starboard.h"
#include "Etc.h"

#import "stb_vorbis.h"
#import <AudioToolbox/ExtendedAudioFile.h>
#import <AudioToolbox/AudioFile.h>
#import <StubReturn.h>

#define kExtAudioFileError_InvalidProperty -66561

extern "C" OSStatus _ExtAudioFileDispose(ExtAudioFileRef fileID);
extern "C" OSStatus _ExtAudioFileOpenURL(CFURLRef url, ExtAudioFileRef* out);
extern "C" OSStatus _ExtAudioFileWrapAudioFileID(AudioFileID fileID, Boolean writing, ExtAudioFileRef* out);
extern "C" OSStatus _ExtAudioFileGetProperty(ExtAudioFileRef fileID, ExtAudioFilePropertyID propID, UInt32* ioDataSize, void* propOutData);
extern "C" OSStatus _ExtAudioFileSetProperty(ExtAudioFileRef fileID,
                                             ExtAudioFilePropertyID propID,
                                             UInt32 ioDataSize,
                                             const void* propInData);
extern "C" OSStatus _ExtAudioFileRead(ExtAudioFileRef fileID, UInt32* numFrames, AudioBufferList* pData);

/**
 @Status Stub
 @Notes
*/
OSStatus ExtAudioFileCreateWithURL(CFURLRef inURL,
                                   AudioFileTypeID inFileType,
                                   const AudioStreamBasicDescription* inStreamDesc,
                                   const AudioChannelLayout* inChannelLayout,
                                   UInt32 inFlags,
                                   ExtAudioFileRef _Nullable* outExtAudioFile) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
OSStatus ExtAudioFileDispose(ExtAudioFileRef fileID) {
    return _ExtAudioFileDispose(fileID);
}

/**
 @Status Caveat
 @Notes Only file:// URLs supported
*/
OSStatus ExtAudioFileOpenURL(CFURLRef url, ExtAudioFileRef* out) {
    return _ExtAudioFileOpenURL(url, out);
}

/**
 @Status Interoperable
*/
OSStatus ExtAudioFileWrapAudioFileID(AudioFileID fileID, Boolean writing, ExtAudioFileRef* out) {
    return _ExtAudioFileWrapAudioFileID(fileID, writing, out);
}

/**
 @Status Caveat
 @Notes Limited properties supported depending on codec
*/
OSStatus ExtAudioFileGetProperty(ExtAudioFileRef fileID, ExtAudioFilePropertyID propID, UInt32* ioDataSize, void* propOutData) {
    return _ExtAudioFileGetProperty(fileID, propID, ioDataSize, propOutData);
}

/**
 @Status Stub
 @Notes
*/
OSStatus ExtAudioFileGetPropertyInfo(ExtAudioFileRef inExtAudioFile,
                                     ExtAudioFilePropertyID inPropertyID,
                                     UInt32* outSize,
                                     Boolean* outWritable) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Only ClientDataFormat property supported
*/
OSStatus ExtAudioFileSetProperty(ExtAudioFileRef fileID, ExtAudioFilePropertyID propID, UInt32 ioDataSize, const void* propInData) {
    return _ExtAudioFileSetProperty(fileID, propID, ioDataSize, propInData);
}

/**
 @Status Interoperable
*/
OSStatus ExtAudioFileRead(ExtAudioFileRef fileID, UInt32* numFrames, AudioBufferList* pData) {
    return _ExtAudioFileRead(fileID, numFrames, pData);
}

/**
 @Status Stub
 @Notes
*/
OSStatus ExtAudioFileSeek(ExtAudioFileRef fileID, SInt64 pos) {
    UNIMPLEMENTED();

    return 0;
}

/**
 @Status Stub
 @Notes
*/
OSStatus ExtAudioFileTell(ExtAudioFileRef inExtAudioFile, SInt64* outFrameOffset) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus ExtAudioFileWrite(ExtAudioFileRef inExtAudioFile, UInt32 inNumberFrames, const AudioBufferList* ioData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus ExtAudioFileWriteAsync(ExtAudioFileRef inExtAudioFile, UInt32 inNumberFrames, const AudioBufferList* ioData) {
    UNIMPLEMENTED();
    return StubReturn();
}