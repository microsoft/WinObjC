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
#import <AudioToolbox/AudioConverter.h>
#import <AudioToolbox/SystemSound.h>
#import <CoreFoundation/CFRunLoop.h>
#import <CoreFoundation/CFString.h>

AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSession_AudioRouteKey_Inputs;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSession_AudioRouteKey_Outputs;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSession_InputSourceKey_ID;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSession_InputSourceKey_Description;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSession_OutputDestinationKey_ID;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSession_OutputDestinationKey_Description;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSession_AudioRouteKey_Type;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionInputRoute_LineIn;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionInputRoute_BuiltInMic;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionInputRoute_HeadsetMic;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionInputRoute_BluetoothHFP;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionInputRoute_USBAudio;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionOutputRoute_LineOut;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionOutputRoute_Headphones;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionOutputRoute_BluetoothHFP;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionOutputRoute_BluetoothA2DP;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionOutputRoute_BuiltInReceiver;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionOutputRoute_BuiltInSpeaker;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionOutputRoute_USBAudio;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionOutputRoute_HDMI;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSessionOutputRoute_AirPlay;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSession_RouteChangeKey_Reason;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSession_AudioRouteChangeKey_PreviousRouteDescription;
AUDIOTOOLBOX_EXPORT const CFStringRef kAudioSession_AudioRouteChangeKey_CurrentRouteDescription;

typedef UInt32 AudioSessionPropertyID;
typedef void (*AudioSessionInterruptionListener)(void* inClientData, UInt32 inInterruptionState);
typedef void (*AudioSessionPropertyListener)(void* inClientData, AudioSessionPropertyID inID, UInt32 inDataSize, const void* inData);
typedef UInt32 AudioSessionInterruptionType;

AUDIOTOOLBOX_EXPORT OSStatus AudioSessionInitialize(CFRunLoopRef inRunLoop,
                                                    CFStringRef inRunLoopMode,
                                                    AudioSessionInterruptionListener inInterruptionListener,
                                                    void* inClientData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionSetActive(Boolean active) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionSetActiveWithFlags(Boolean active, UInt32 inFlags) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionGetProperty(AudioSessionPropertyID inID, UInt32* ioDataSize, void* outData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionSetProperty(AudioSessionPropertyID inID, UInt32 inDataSize, const void* inData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionGetPropertySize(AudioSessionPropertyID inID, UInt32* outDataSize) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionAddPropertyListener(AudioSessionPropertyID inID,
                                                             AudioSessionPropertyListener inProc,
                                                             void* inClientData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionRemovePropertyListenerWithUserData(AudioSessionPropertyID inID,
                                                                            AudioSessionPropertyListener inProc,
                                                                            void* inClientData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioSessionRemovePropertyListener(AudioSessionPropertyID inID) STUB_METHOD;
