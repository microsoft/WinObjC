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
#pragma once

#import <AudioToolbox/AudioToolboxExport.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <AudioToolbox/AudioConverter.h>
#import <CoreFoundation/CFURL.h>
#import <AudioToolbox/AudioFile.h>

enum {
    kExtAudioFileProperty_FileDataFormat = 'ffmt',
    kExtAudioFileProperty_FileChannelLayout = 'fclo',
    kExtAudioFileProperty_ClientDataFormat = 'cfmt',
    kExtAudioFileProperty_ClientChannelLayout = 'cclo',
    kExtAudioFileProperty_CodecManufacturer = 'cman',
    // read-only properties
    kExtAudioFileProperty_AudioConverter = 'acnv',
    kExtAudioFileProperty_AudioFile = 'afil',
    kExtAudioFileProperty_FileMaxPacketSize = 'fmps',
    kExtAudioFileProperty_ClientMaxPacketSize = 'cmps',
    kExtAudioFileProperty_FileLengthFrames = '#frm',
    // read/write properties
    kExtAudioFileProperty_ConverterConfig = 'accf',
    kExtAudioFileProperty_IOBufferSizeBytes = 'iobs',
    kExtAudioFileProperty_IOBuffer = 'iobf',
    kExtAudioFileProperty_PacketTable = 'xpti'
};

enum {
    kExtAudioFileError_CodecUnavailableInputConsumed = -66559,
    kExtAudioFileError_CodecUnavailableInputNotConsumed = -66560,
    kExtAudioFileError_InvalidProperty = -66561,
    kExtAudioFileError_InvalidPropertySize = -66562,
    kExtAudioFileError_NonPCMClientFormat = -66563,
    kExtAudioFileError_InvalidChannelMap = -66564,
    kExtAudioFileError_InvalidOperationOrder = -66565,
    kExtAudioFileError_InvalidDataFormat = -66566,
    kExtAudioFileError_MaxPacketSizeUnknown = -66567,
    kExtAudioFileError_InvalidSeek = -66568,
    kExtAudioFileError_AsyncWriteTooLarge = -66569,
    kExtAudioFileError_AsyncWriteBufferOverflow = -66570
};

typedef struct OpaqueExtAudioFile* ExtAudioFileRef;
typedef UInt32 ExtAudioFilePropertyID;

AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileCreateWithURL(CFURLRef inURL,
                                                       AudioFileTypeID inFileType,
                                                       const AudioStreamBasicDescription* inStreamDesc,
                                                       const AudioChannelLayout* inChannelLayout,
                                                       UInt32 inFlags,
                                                       ExtAudioFileRef _Nullable* outExtAudioFile) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileDispose(ExtAudioFileRef inExtAudioFile);
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileOpenURL(CFURLRef inURL, ExtAudioFileRef _Nullable* outExtAudioFile);
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileWrapAudioFileID(AudioFileID inFileID,
                                                         Boolean inForWriting,
                                                         ExtAudioFileRef _Nullable* outExtAudioFile);
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileGetProperty(ExtAudioFileRef inExtAudioFile,
                                                     ExtAudioFilePropertyID inPropertyID,
                                                     UInt32* ioPropertyDataSize,
                                                     void* outPropertyData);
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileGetPropertyInfo(ExtAudioFileRef inExtAudioFile,
                                                         ExtAudioFilePropertyID inPropertyID,
                                                         UInt32* outSize,
                                                         Boolean* outWritable) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileSetProperty(ExtAudioFileRef inExtAudioFile,
                                                     ExtAudioFilePropertyID inPropertyID,
                                                     UInt32 inPropertyDataSize,
                                                     const void* inPropertyData);
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileRead(ExtAudioFileRef inExtAudioFile, UInt32* ioNumberFrames, AudioBufferList* ioData);
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileSeek(ExtAudioFileRef inExtAudioFile, SInt64 inFrameOffset) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileTell(ExtAudioFileRef inExtAudioFile, SInt64* outFrameOffset) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileWrite(ExtAudioFileRef inExtAudioFile,
                                               UInt32 inNumberFrames,
                                               const AudioBufferList* ioData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileWriteAsync(ExtAudioFileRef inExtAudioFile,
                                                    UInt32 inNumberFrames,
                                                    const AudioBufferList* ioData) STUB_METHOD;