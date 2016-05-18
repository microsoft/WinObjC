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


// Calls into C++ to access Windows.Phone.Devices.Notification namespace to vibrate devices with vibration capability.
void vibrate();

static const wchar_t* TAG = L"AudioToolbox";

// We generate SystemSoundIDs starting with 5001 as some system supplied sounds have ids below 5000.
static const SystemSoundID c_userSSID = 5000;

// We use the NSMutableDictionary to map SystemSoundID to URL via a SystemSound object.
NSMutableDictionary* _ssObjects = [NSMutableDictionary dictionary];

// The following variables and methods keep track of the currently playing file 
// and call the respective callback function if any.
static SystemSoundID _latestSSID = 0;
static int _numberOfCallbacksRegistered = 0;
static EventRegistrationToken _MediaEndedToken;
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
    SystemSoundID _ssID;
    void* _clientData;
}


- (instancetype)initWithContentsOfURL:(CFURLRef)inFileURL forSSID:(SystemSoundID)ssID {

    if (self = [super init]) {
        _ssID = ssID;

        //__bridge casting not supported yet for conversions between NSURL* and CFURLRef
        NSURL* url = (/*__bridge*/ NSURL*)inFileURL;
        NSString* scheme = [url scheme];

        if (scheme == nil || [scheme isEqualToString:@"file"]) {
            NSURL* appxurl = [[NSURL alloc] initFileURLWithPath:url.path];

            TraceInfo(TAG, L"Loading media at file URL: %hs\n", [appxurl.absoluteString UTF8String]);

            _mediaUri = [WFUri makeUri:[NSString stringWithFormat:@"ms-appx://%@", appxurl.path]];
        } else {
            _mediaUri = [WFUri makeUri:url.absoluteString];

            TraceInfo(TAG, L"Loading media at URI: %hs\n", [_mediaUri.absoluteUri UTF8String]);
        }
    }

    return self;
}


- (void)runCallbackFunction {

    if (_callbackFunction != nullptr) {
        dispatch_async(dispatch_get_main_queue(), ^{ _callbackFunction(_ssID, _clientData); });
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

    if (_latestSSID > c_userSSID) {
        SystemSound* object = _ssObjects[[NSNumber numberWithUnsignedInt:_latestSSID]];

        std::lock_guard<std::mutex> lock(_mutex);
        _latestSSID = 0;

        if (object) {
            [object runCallbackFunction];
        }
    }
}


/**
 @Status Interoperable
 @Notes
*/
OSStatus AudioServicesCreateSystemSoundID(CFURLRef inFileURL, SystemSoundID* outSystemSoundID) {
    static SystemSoundID lastSSID = c_userSSID;

    if (inFileURL) {         
        SystemSound* object = [[SystemSound alloc] initWithContentsOfURL:inFileURL forSSID:++lastSSID];
        *outSystemSoundID = lastSSID;
        [_ssObjects setObject:object forKey:[NSNumber numberWithUnsignedInt:*outSystemSoundID]];
        return kAudioServicesNoError;
    }
    
    return kAudioServicesSystemSoundUnspecifiedError;
}


/**
 @Status Interoperable
 @Notes
*/
OSStatus AudioServicesDisposeSystemSoundID(SystemSoundID inSystemSoundID) {

    if (inSystemSoundID > c_userSSID) {

        // This insures _numberOfCallbacksRegistered variable is decremented.
        AudioServicesRemoveSystemSoundCompletion(inSystemSoundID);

        [_ssObjects removeObjectForKey:[NSNumber numberWithUnsignedInt:inSystemSoundID]];
        return kAudioServicesNoError;
    }

    return kAudioServicesSystemSoundUnspecifiedError;
}


// Plays the sound file and calls vibrate() as needed.
static inline void _playSound(SystemSoundID inSystemSoundID, BOOL vibration) {

    if (inSystemSoundID > c_userSSID) {
        SystemSound* object = _ssObjects[[NSNumber numberWithUnsignedInt:inSystemSoundID]];

        if (object) {
            WMPMediaPlayer* mediaPlayer = [WMPBackgroundMediaPlayer current];
            
            if (mediaPlayer.currentState == WMPMediaPlayerStatePlaying) {
                [mediaPlayer pause];

                // This runs the callback function, if any, for the audio file that was playing.
                _handleMediaEndedEvent();
            }

            [mediaPlayer setAutoPlay:false];
            [mediaPlayer setIsLoopingEnabled:false];

            if (vibration) {
                vibrate();
            }

            _latestSSID = inSystemSoundID;
            [mediaPlayer setUriSource:[object mediaUri]];
            [mediaPlayer play];
        }
    } else if (inSystemSoundID == kSystemSoundID_Vibrate) {
        vibrate();        
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
    
    if (inSystemSoundID > c_userSSID) {
        SystemSound* object = _ssObjects[[NSNumber numberWithUnsignedInt:inSystemSoundID]];

        if (object) {

            // Registers for WMPMediaPlayer event if there aren't any audio files with callback function registered yet.
            if (_numberOfCallbacksRegistered == 0) {
                WMPMediaPlayer* mediaPlayer = [WMPBackgroundMediaPlayer current];
                _MediaEndedToken = [mediaPlayer addMediaEndedEvent:^(WMPMediaPlayer* mediaPlayer, RTObject* e){ 
                                                                        _handleMediaEndedEvent(); 
                                                                    }];
            }

            std::lock_guard<std::mutex> lock(_mutex);

            if (object.callbackRegistered == false) {
                ++_numberOfCallbacksRegistered;
            }

            [object setCallbackFunction:inCompletionRoutine withClientData:inClientData];
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

    if (inSystemSoundID > c_userSSID) {
        SystemSound* object = _ssObjects[[NSNumber numberWithUnsignedInt:inSystemSoundID]];
        
        if (object) {
            std::lock_guard<std::mutex> lock(_mutex);

            if (object.callbackRegistered == true) {
                --_numberOfCallbacksRegistered;
            }

            // Unregisters from WMPMediaPlayer events when none of the audio files have callback function registered;
            if (_numberOfCallbacksRegistered == 0) {
                WMPMediaPlayer* mediaPlayer = [WMPBackgroundMediaPlayer current];
                [mediaPlayer removeMediaEndedEvent:_MediaEndedToken];
            }

            if (_latestSSID == inSystemSoundID) {
                _latestSSID = 0;
            }

            [object removeCallbackFunction];
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