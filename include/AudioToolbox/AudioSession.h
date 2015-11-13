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

#ifndef _AUDIOSESSION_H_
#define _AUDIOSESSION_H_

#import <CoreFoundation/CoreFoundation.h>
#import <StarboardExport.h>
#import <AudioToolbox/AudioToolboxExport.h>
#import <stdint.h>

enum {
    kAudioSessionNoError = 0,
    kAudioSessionNotInitialized = '!ini',
    kAudioSessionAlreadyInitialized = 'init',
    kAudioSessionInitializationError = 'ini?',
    kAudioSessionUnsupportedPropertyError = 'pty?',
    kAudioSessionBadPropertySizeError = '!siz',
    kAudioSessionNotActiveError = '!act',
    kAudioServicesNoHardwareError = 'nohw',
    kAudioSessionNoCategorySet = '?cat',
    kAudioSessionIncompatibleCategory = '!cat',
    kAudioSessionUnspecifiedError = 'what'
};

enum {
    kAudioSessionInterruptionType_ShouldResume = 'irsm',
    kAudioSessionInterruptionType_ShouldNotResume = '!rsm',
};
typedef uint32_t AudioSessionInterruptionType;
typedef uint32_t AudioSessionPropertyID;
typedef void (*AudioSessionPropertyListener)(void* inClientData, AudioSessionPropertyID inID, UInt32 inDataSize, const void* inData);

enum {
    kAudioSessionProperty_PreferredHardwareSampleRate = 'hwsr',
    kAudioSessionProperty_PreferredHardwareIOBufferDuration = 'iobd',
    kAudioSessionProperty_AudioCategory = 'acat',
    kAudioSessionProperty_AudioRouteChange = 'roch',
    kAudioSessionProperty_CurrentHardwareSampleRate = 'chsr',
    kAudioSessionProperty_CurrentHardwareInputNumberChannels = 'chic',
    kAudioSessionProperty_CurrentHardwareOutputNumberChannels = 'choc',
    kAudioSessionProperty_CurrentHardwareOutputVolume = 'chov',
    kAudioSessionProperty_CurrentHardwareInputLatency = 'cilt',
    kAudioSessionProperty_CurrentHardwareOutputLatency = 'colt',
    kAudioSessionProperty_CurrentHardwareIOBufferDuration = 'chbd',
    kAudioSessionProperty_OtherAudioIsPlaying = 'othr',
    kAudioSessionProperty_OverrideAudioRoute = 'ovrd',
    kAudioSessionProperty_AudioInputAvailable = 'aiav',
    kAudioSessionProperty_ServerDied = 'died',
    kAudioSessionProperty_OtherMixableAudioShouldDuck = 'duck',
    kAudioSessionProperty_OverrideCategoryMixWithOthers = 'cmix',
    kAudioSessionProperty_OverrideCategoryDefaultToSpeaker = 'cspk',
    kAudioSessionProperty_OverrideCategoryEnableBluetoothInput = 'cblu',
    kAudioSessionProperty_InterruptionType = 'type',
    kAudioSessionProperty_Mode = 'mode',
    kAudioSessionProperty_InputSources = 'srcs',
    kAudioSessionProperty_OutputDestinations = 'dsts',
    kAudioSessionProperty_InputSource = 'isrc',
    kAudioSessionProperty_OutputDestination = 'odst',
    kAudioSessionProperty_InputGainAvailable = 'igav',
    kAudioSessionProperty_InputGainScalar = 'igsc',
    kAudioSessionProperty_AudioRouteDescription = 'crar',
    kAudioSessionProperty_AudioRoute = 'rout'
};

enum {
    AVAudioSessionInterruptionFlags_ShouldResume = 1,
};

typedef uint32_t AudioSessionPropertyID;

enum {
    kAudioSessionBeginInterruption = 1,
    kAudioSessionEndInterruption = 0,
};

enum {
    kAudioSessionCategory_AmbientSound = 'ambi',
    kAudioSessionCategory_SoloAmbientSound = 'solo',
    kAudioSessionCategory_MediaPlayback = 'medi',
    kAudioSessionCategory_RecordAudio = 'reca',
    kAudioSessionCategory_PlayAndRecord = 'plar',
    kAudioSessionCategory_AudioProcessing = 'proc'
};

typedef void (*AudioSessionInterruptionListener)(void* inClientData, UInt32 inInterruptionState);

AUDIOTOOLBOX_EXPORT OSStatus AudioSessionGetProperty(AudioSessionPropertyID id, UInt32* dataSize, void* outData);
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionSetActive(Boolean active);
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionAddPropertyListener(AudioSessionPropertyID inID,
                                                             AudioSessionPropertyListener inProc,
                                                             void* inClientData);
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionInitialize(CFRunLoopRef inRunLoop,
                                                    CFStringRef inRunLoopMode,
                                                    AudioSessionInterruptionListener inInterruptionListener,
                                                    void* inClientData);
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionSetProperty(AudioSessionPropertyID inID, UInt32 inDataSize, const void* inData);

#endif // _AUDIOSESSION_H_
