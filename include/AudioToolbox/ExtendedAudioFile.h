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

#ifndef _EXTENDEDAUDIOFILE_H_
#define _EXTENDEDAUDIOFILE_H_

#import <AudioToolbox/AudioToolboxExport.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <CoreFoundation/CFURL.h>

typedef uint32_t ExtAudioFilePropertyID;
struct ExtAudioFile;
typedef struct ExtAudioFile* ExtAudioFileRef;

enum {
    kExtAudioFileProperty_FileDataFormat = 'ffmt',
    kExtAudioFileProperty_FileChannelLayout = 'fclo',
    kExtAudioFileProperty_ClientDataFormat = 'cfmt',
    kExtAudioFileProperty_ClientChannelLayout = 'cclo',
    kExtAudioFileProperty_CodecManufacturer = 'cman',
    kExtAudioFileProperty_AudioConverter = 'acnv',
    kExtAudioFileProperty_AudioFile = 'afil',
    kExtAudioFileProperty_FileMaxPacketSize = 'fmps',
    kExtAudioFileProperty_ClientMaxPacketSize = 'cmps',
    kExtAudioFileProperty_FileLengthFrames = '#frm',
    kExtAudioFileProperty_ConverterConfig = 'accf',
    kExtAudioFileProperty_IOBufferSizeBytes = 'iobs',
    kExtAudioFileProperty_IOBuffer = 'iobf',
    kExtAudioFileProperty_PacketTable = 'xpti'
};

AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileOpenURL(CFURLRef inURL, ExtAudioFileRef* outExtAudioFile);
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileGetProperty(ExtAudioFileRef inExtAudioFile,
                                                     ExtAudioFilePropertyID inPropertyID,
                                                     UInt32* ioPropertyDataSize,
                                                     void* outPropertyData);
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileSetProperty(ExtAudioFileRef inExtAudioFile,
                                                     ExtAudioFilePropertyID inPropertyID,
                                                     UInt32 inPropertyDataSize,
                                                     const void* inPropertyData);
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileRead(ExtAudioFileRef inExtAudioFile, UInt32* ioNumberFrames, AudioBufferList* ioData);
AUDIOTOOLBOX_EXPORT OSStatus ExtAudioFileDispose(ExtAudioFileRef inExtAudioFile);

#endif // _EXTENDEDAUDIOFILE_H_