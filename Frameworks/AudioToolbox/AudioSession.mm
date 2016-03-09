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

#import <AudioToolbox/AudioSession.h>
#import <AudioToolbox/AudioServices.h>
#import <StubReturn.h>

const CFStringRef kAudioSession_AudioRouteKey_Inputs = static_cast<CFStringRef>(@"AS_AudioRouteKey_Inputs");
const CFStringRef kAudioSession_AudioRouteKey_Outputs = static_cast<CFStringRef>(@"AS_AudioRouteKey_Outputs");
const CFStringRef kAudioSession_InputSourceKey_ID = static_cast<CFStringRef>(@"AS_InputSourceKey_ID");
const CFStringRef kAudioSession_InputSourceKey_Description = static_cast<CFStringRef>(@"AS_InputSourceKey_Description");
const CFStringRef kAudioSession_OutputDestinationKey_ID = static_cast<CFStringRef>(@"AS_OutputDestinationKey_ID");
const CFStringRef kAudioSession_OutputDestinationKey_Description = static_cast<CFStringRef>(@"AS_OutputDestinationKey_Description");
const CFStringRef kAudioSession_AudioRouteKey_Type = static_cast<CFStringRef>(@"AS_AudioRouteKey_Type");
const CFStringRef kAudioSessionInputRoute_LineIn = static_cast<CFStringRef>(@"AS_InputRoute_LineIn");
const CFStringRef kAudioSessionInputRoute_BuiltInMic = static_cast<CFStringRef>(@"AS_InputRoute_BuiltInMic");
const CFStringRef kAudioSessionInputRoute_HeadsetMic = static_cast<CFStringRef>(@"AS_InputRoute_HeadsetMic");
const CFStringRef kAudioSessionInputRoute_BluetoothHFP = static_cast<CFStringRef>(@"AS_InputRoute_BluetoothHFP");
const CFStringRef kAudioSessionInputRoute_USBAudio = static_cast<CFStringRef>(@"AS_InputRoute_USBAudio");
const CFStringRef kAudioSessionOutputRoute_LineOut = static_cast<CFStringRef>(@"AS_OutputRoute_LineOut");
const CFStringRef kAudioSessionOutputRoute_Headphones = static_cast<CFStringRef>(@"AS_OutputRoute_Headphones");
const CFStringRef kAudioSessionOutputRoute_BluetoothHFP = static_cast<CFStringRef>(@"AS_OutputRoute_BluetoothHFP");
const CFStringRef kAudioSessionOutputRoute_BluetoothA2DP = static_cast<CFStringRef>(@"AS_OutputRoute_BluetoothA2DP");
const CFStringRef kAudioSessionOutputRoute_BuiltInReceiver = static_cast<CFStringRef>(@"AS_OutputRoute_BuiltInReceiver");
const CFStringRef kAudioSessionOutputRoute_BuiltInSpeaker = static_cast<CFStringRef>(@"AS_OutputRoute_BuiltInSpeaker");
const CFStringRef kAudioSessionOutputRoute_USBAudio = static_cast<CFStringRef>(@"AS_OutputRoute_USBAudio");
const CFStringRef kAudioSessionOutputRoute_HDMI = static_cast<CFStringRef>(@"AS_OutputRoute_HDMI");
const CFStringRef kAudioSessionOutputRoute_AirPlay = static_cast<CFStringRef>(@"AS_OutputRoute_AirPlay");
const CFStringRef kAudioSession_RouteChangeKey_Reason = static_cast<CFStringRef>(@"AS_RouteChangeKey_Reason");
const CFStringRef kAudioSession_AudioRouteChangeKey_PreviousRouteDescription =
    static_cast<CFStringRef>(@"AS_AudioRouteChangeKey_PreviousRouteDescription");
const CFStringRef kAudioSession_AudioRouteChangeKey_CurrentRouteDescription =
    static_cast<CFStringRef>(@"AS_AudioRouteChangeKey_CurrentRouteDescription");

/**
 @Status Stub
 @Notes
*/
OSStatus AudioSessionInitialize(CFRunLoopRef inRunLoop,
                                CFStringRef inRunLoopMode,
                                AudioSessionInterruptionListener inInterruptionListener,
                                void* inClientData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioSessionSetActive(Boolean active) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioSessionSetActiveWithFlags(Boolean active, UInt32 inFlags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioSessionGetProperty(AudioSessionPropertyID inID, UInt32* ioDataSize, void* outData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioSessionSetProperty(AudioSessionPropertyID inID, UInt32 inDataSize, const void* inData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioSessionGetPropertySize(AudioSessionPropertyID inID, UInt32* outDataSize) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioSessionAddPropertyListener(AudioSessionPropertyID inID, AudioSessionPropertyListener inProc, void* inClientData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioSessionRemovePropertyListenerWithUserData(AudioSessionPropertyID inID,
                                                        AudioSessionPropertyListener inProc,
                                                        void* inClientData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioSessionRemovePropertyListener(AudioSessionPropertyID inID) {
    UNIMPLEMENTED();
    return StubReturn();
}
