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
#pragma once

#import <AudioToolbox/AudioToolboxExport.h>
#import <AudioToolbox/AudioConverter.h>
#import <CoreFoundation/CFURL.h>
#import <CoreFoundation/CFRunLoop.h>
#import <CoreFoundation/CFString.h>

enum { kSystemSoundID_Vibrate = 0x00000FFF };

enum {
    kAudioServicesNoError = 0,
    kAudioServicesUnsupportedPropertyError = 'pty?',
    kAudioServicesBadPropertySizeError = '!siz',
    kAudioServicesBadSpecifierSizeError = '!spc',
    kAudioServicesSystemSoundUnspecifiedError = -1500,
    kAudioServicesSystemSoundClientTimedOutError = -1501
};

typedef UInt32 AudioServicesPropertyID;
typedef UInt32 SystemSoundID;
typedef void (*AudioServicesSystemSoundCompletionProc)(SystemSoundID ssID, void* clientData);

AUDIOTOOLBOX_EXPORT OSStatus AudioServicesCreateSystemSoundID(CFURLRef inFileURL, SystemSoundID* outSystemSoundID);
AUDIOTOOLBOX_EXPORT OSStatus AudioServicesDisposeSystemSoundID(SystemSoundID inSystemSoundID);
AUDIOTOOLBOX_EXPORT void AudioServicesPlayAlertSound(SystemSoundID inSystemSoundID);
AUDIOTOOLBOX_EXPORT void AudioServicesPlaySystemSound(SystemSoundID inSystemSoundID);
AUDIOTOOLBOX_EXPORT OSStatus AudioServicesAddSystemSoundCompletion(SystemSoundID inSystemSoundID,
                                                                   CFRunLoopRef inRunLoop,
                                                                   CFStringRef inRunLoopMode,
                                                                   AudioServicesSystemSoundCompletionProc inCompletionRoutine,
                                                                   void* inClientData);
AUDIOTOOLBOX_EXPORT void AudioServicesRemoveSystemSoundCompletion(SystemSoundID inSystemSoundID);
AUDIOTOOLBOX_EXPORT OSStatus AudioServicesGetPropertyInfo(AudioServicesPropertyID inPropertyID,
                                                          UInt32 inSpecifierSize,
                                                          const void* inSpecifier,
                                                          UInt32* outPropertyDataSize,
                                                          Boolean* outWritable) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioServicesGetProperty(AudioServicesPropertyID inPropertyID,
                                                      UInt32 inSpecifierSize,
                                                      const void* inSpecifier,
                                                      UInt32* ioPropertyDataSize,
                                                      void* outPropertyData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioServicesSetProperty(AudioServicesPropertyID inPropertyID,
                                                      UInt32 inSpecifierSize,
                                                      const void* inSpecifier,
                                                      UInt32 inPropertyDataSize,
                                                      const void* inPropertyData) STUB_METHOD;