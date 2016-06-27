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

#import <AudioToolbox/SystemSound.h>
#import <StubReturn.h>
#import <Starboard.h>
#import <UWP/WindowsMediaPlayback.h>
#import <mutex>
#import <NSBundleInternal.h>
#import <NSLogging.h>
#import "AssertARCEnabled.h"

#include <COMIncludes.h>
#import <wrl\wrappers\corewrappers.h>
#import <windows.phone.devices.notification.h>
#import <windows.foundation.metadata.h>
#include <COMIncludes_End.h>

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::Windows::Phone::Devices::Notification;
using namespace ABI::Windows::Foundation;

static const wchar_t* TAG = L"AudioToolbox";

// We generate SystemSoundIDs starting with 5001 as some system supplied sounds have ids below 5000.
static const SystemSoundID c_systemSoundIDStart = 5000;

// We use the NSMutableDictionary to map SystemSoundID to URL via a SystemSound object.
NSMutableDictionary* _systemSoundDictionary = [NSMutableDictionary dictionary];

// The following variables and methods keep track of the currently playing file 
// and call the respective callback function if any.
static SystemSoundID _latestSystemSoundID = 0;
static int _numberOfCallbacksRegistered = 0;
static EventRegistrationToken _mediaEndedToken;
static std::mutex _mutex;
void _handleMediaEndedEvent(); 


// Local class to store URL and callback function for an audio file.
@interface SystemSound : NSObject
@property WFUri* mediaUri;
@property BOOL callbackRegistered;
- (void)setCallbackFunction:(AudioServicesSystemSoundCompletionProc)callbackFunction withClientData:(void*)clientData;
- (void)runCallbackFunction;
@end


@implementation SystemSound {
    AudioServicesSystemSoundCompletionProc _callbackFunction;
    SystemSoundID _systemSoundID;
    void* _clientData;
}


- (instancetype)initWithContentsOfURL:(CFURLRef)inFileURL forSystemSoundID:(SystemSoundID)systemSoundID {

    if (self = [super init]) {
        _systemSoundID = systemSoundID;

        NSURL* url = [[NSBundle mainBundle] _msAppxURLForResourceWithURL:(__bridge NSURL*)inFileURL];
        _mediaUri = [WFUri makeUri:url.absoluteString];
        TraceInfo(TAG, L"Loading media at URI: %hs\n", [_mediaUri.absoluteUri UTF8String]);  
    }

    return self;
}


- (void)runCallbackFunction {

    if (_callbackFunction != nullptr) {
        dispatch_async(dispatch_get_main_queue(), ^{ _callbackFunction(_systemSoundID, _clientData); });
    }
}


- (void)setCallbackFunction:(AudioServicesSystemSoundCompletionProc)callbackFunction withClientData:(void*)clientData {
    self.callbackRegistered = true;
    _callbackFunction = callbackFunction;
    _clientData = clientData;
}


- (void)removeCallbackFunction {
    self.callbackRegistered = false;
    _callbackFunction = nil;
    _clientData = nil;
}
@end


// Runs the callback function, if any, of the latest playing audio file.
void _handleMediaEndedEvent() {

    if (_latestSystemSoundID > c_systemSoundIDStart) {
        SystemSound* systemSoundObject = _systemSoundDictionary[[NSNumber numberWithUnsignedInt:_latestSystemSoundID]];

        std::lock_guard<std::mutex> lock(_mutex);
        _latestSystemSoundID = 0;

        if (systemSoundObject) {
            [systemSoundObject runCallbackFunction];
        }
    }
}


/**
 @Status Interoperable
 @Notes
*/
OSStatus AudioServicesCreateSystemSoundID(CFURLRef inFileURL, SystemSoundID* outSystemSoundID) {
    static SystemSoundID lastSystemSoundID = c_systemSoundIDStart;

    if (inFileURL) {         
        SystemSound* systemSoundObject = [[SystemSound alloc] initWithContentsOfURL:inFileURL forSystemSoundID:++lastSystemSoundID];
        *outSystemSoundID = lastSystemSoundID;
        [_systemSoundDictionary setObject:systemSoundObject forKey:[NSNumber numberWithUnsignedInt:*outSystemSoundID]];
        return kAudioServicesNoError;
    }
    
    return kAudioServicesSystemSoundUnspecifiedError;
}


/**
 @Status Interoperable
 @Notes
*/
OSStatus AudioServicesDisposeSystemSoundID(SystemSoundID inSystemSoundID) {

    if (inSystemSoundID > c_systemSoundIDStart) {

        // This insures _numberOfCallbacksRegistered variable is decremented.
        AudioServicesRemoveSystemSoundCompletion(inSystemSoundID);

        [_systemSoundDictionary removeObjectForKey:[NSNumber numberWithUnsignedInt:inSystemSoundID]];
        return kAudioServicesNoError;
    }

    return kAudioServicesSystemSoundUnspecifiedError;
}


// Calls into C++ to access Windows.Phone.Devices.Notification namespace to vibrate devices with vibration capability.
void vibrateDevice() {
    Boolean vibrationCapable = false;
    HRESULT status; 
    
    ComPtr<Metadata::IApiInformationStatics> apiInformation;
    status = GetActivationFactory(HStringReference(RuntimeClass_Windows_Foundation_Metadata_ApiInformation).Get(),
                                                   &apiInformation);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"Metadata::ApiInformation activation failed");
        return;
    }

    status = apiInformation->IsTypePresent(HStringReference(RuntimeClass_Windows_Phone_Devices_Notification_VibrationDevice).Get(), 
                                           &vibrationCapable);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"VibrationDevice availability check failed");
        return;
    }

    if (vibrationCapable) {
        ComPtr<IVibrationDevice> vibrationDevice;

        ComPtr<IVibrationDeviceStatics> vibrationDeviceStatics;
        status = GetActivationFactory(HStringReference(RuntimeClass_Windows_Phone_Devices_Notification_VibrationDevice).Get(),
                                                       &vibrationDeviceStatics);
        if (!SUCCEEDED(status)) {
            NSTraceInfo(TAG, @"VibrationDevice activation failed");
            return;
        }
        status = vibrationDeviceStatics->GetDefault(&vibrationDevice);
        if (!SUCCEEDED(status)) {
            NSTraceInfo(TAG, @"VibrationDevice GetDefault() failed");
            return;
        }

        // Vibration duration set as 0.5 second. The unit is 100-nanoseconds. 
        TimeSpan vibrationDuration = { 5000000 };

        status = vibrationDevice->Vibrate(vibrationDuration);
        if (!SUCCEEDED(status)) {
            NSTraceInfo(TAG, @"VibrationDevice Vibrate() failed");
            return;
        }
    }
}


// Plays the sound file and calls vibrateDevice() as needed.
static inline void _playSound(SystemSoundID inSystemSoundID, BOOL vibration) {

    if (inSystemSoundID > c_systemSoundIDStart) {
        SystemSound* systemSoundObject = _systemSoundDictionary[[NSNumber numberWithUnsignedInt:inSystemSoundID]];

        if (systemSoundObject) {
            WMPMediaPlayer* mediaPlayer = [WMPBackgroundMediaPlayer current];
            
            if (mediaPlayer.currentState == WMPMediaPlayerStatePlaying) {
                [mediaPlayer pause];

                // This runs the callback function, if any, for the audio file that was playing.
                _handleMediaEndedEvent();
            }

            [mediaPlayer setAutoPlay:false];
            [mediaPlayer setIsLoopingEnabled:false];

            if (vibration) {
                vibrateDevice();
            }

            _latestSystemSoundID = inSystemSoundID;
            [mediaPlayer setUriSource:[systemSoundObject mediaUri]];
            [mediaPlayer play];
        }
    } else if (inSystemSoundID == kSystemSoundID_Vibrate) {
        vibrateDevice();        
    } else if (inSystemSoundID > 0) {
        // System supplied sounds not supported. 
        UNIMPLEMENTED();
    }
}


/**
 @Status Interoperable
 @Notes System supplied sounds are not supported.
*/
void AudioServicesPlayAlertSound(SystemSoundID inSystemSoundID) {
    _playSound(inSystemSoundID, true);
}


/**
 @Status Interoperable
 @Notes System supplied sounds are not supported.
*/
void AudioServicesPlaySystemSound(SystemSoundID inSystemSoundID) {
    _playSound(inSystemSoundID, false);
}


/**
 @Status Caveat
 @Notes Currenlty we are ignoring inRunLoop and inRunLoopMode and running the callback function on the main queue.
*/
OSStatus AudioServicesAddSystemSoundCompletion(SystemSoundID inSystemSoundID,
                                               CFRunLoopRef inRunLoop,
                                               CFStringRef inRunLoopMode,
                                               AudioServicesSystemSoundCompletionProc inCompletionRoutine,
                                               void* inClientData) {
    
    if (inSystemSoundID > c_systemSoundIDStart) {
        SystemSound* systemSoundObject = _systemSoundDictionary[[NSNumber numberWithUnsignedInt:inSystemSoundID]];

        if (systemSoundObject) {

            // Registers for WMPMediaPlayer event if there aren't any audio files with callback function registered yet.
            if (_numberOfCallbacksRegistered == 0) {
                WMPMediaPlayer* mediaPlayer = [WMPBackgroundMediaPlayer current];
                _mediaEndedToken = [mediaPlayer addMediaEndedEvent:^(WMPMediaPlayer* mediaPlayer, RTObject* e){ 
                                                                        _handleMediaEndedEvent(); 
                                                                    }];
            }

            std::lock_guard<std::mutex> lock(_mutex);

            if (systemSoundObject.callbackRegistered == false) {
                ++_numberOfCallbacksRegistered;
            }

            [systemSoundObject setCallbackFunction:inCompletionRoutine withClientData:inClientData];
            return kAudioServicesNoError;
        }   
    }

    return kAudioServicesSystemSoundUnspecifiedError;
}


/**
 @Status Interoperable
 @Notes
*/
void AudioServicesRemoveSystemSoundCompletion(SystemSoundID inSystemSoundID) {

    if (inSystemSoundID > c_systemSoundIDStart) {
        SystemSound* systemSoundObject = _systemSoundDictionary[[NSNumber numberWithUnsignedInt:inSystemSoundID]];
        
        if (systemSoundObject) {
            std::lock_guard<std::mutex> lock(_mutex);

            if (systemSoundObject.callbackRegistered == true) {
                --_numberOfCallbacksRegistered;
            }

            // Unregisters from WMPMediaPlayer events when none of the audio files have callback function registered;
            if (_numberOfCallbacksRegistered == 0) {
                WMPMediaPlayer* mediaPlayer = [WMPBackgroundMediaPlayer current];
                [mediaPlayer removeMediaEndedEvent:_mediaEndedToken];
            }

            if (_latestSystemSoundID == inSystemSoundID) {
                _latestSystemSoundID = 0;
            }

            [systemSoundObject removeCallbackFunction];
        }
    }
}


/**
 @Status Stub
 @Notes
*/
OSStatus AudioServicesGetPropertyInfo(AudioServicesPropertyID inPropertyID,
                                      UInt32 inSpecifierSize,
                                      const void* inSpecifier,
                                      UInt32* outPropertyDataSize,
                                      Boolean* outWritable) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioServicesGetProperty(AudioServicesPropertyID inPropertyID,
                                  UInt32 inSpecifierSize,
                                  const void* inSpecifier,
                                  UInt32* ioPropertyDataSize,
                                  void* outPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioServicesSetProperty(AudioServicesPropertyID inPropertyID,
                                  UInt32 inSpecifierSize,
                                  const void* inSpecifier,
                                  UInt32 inPropertyDataSize,
                                  const void* inPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}