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

#import <AVFoundation/AVFoundation.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

NSString* const AVAudioSessionCategoryAmbient = @"AVAudioSessionCategoryAmbient";
NSString* const AVAudioSessionCategorySoloAmbient = @"AVAudioSessionCategorySoloAmbient";
NSString* const AVAudioSessionCategoryPlayback = @"AVAudioSessionCategoryPlayback";
NSString* const AVAudioSessionCategoryRecord = @"AVAudioSessionCategoryRecord";
NSString* const AVAudioSessionCategoryPlayAndRecord = @"AVAudioSessionCategoryPlayAndRecord";
NSString* const AVAudioSessionCategoryAudioProcessing = @"AVAudioSessionCategoryAudioProcessing";
NSString* const AVAudioSessionCategoryMultiRoute = @"AVAudioSessionCategoryMultiRoute";
NSString* const AVAudioSessionModeDefault = @"AVAudioSessionModeDefault";
NSString* const AVAudioSessionModeVoiceChat = @"AVAudioSessionModeVoiceChat";
NSString* const AVAudioSessionModeGameChat = @"AVAudioSessionModeGameChat";
NSString* const AVAudioSessionModeVideoRecording = @"AVAudioSessionModeVideoRecording";
NSString* const AVAudioSessionModeMeasurement = @"AVAudioSessionModeMeasurement";
NSString* const AVAudioSessionModeMoviePlayback = @"AVAudioSessionModeMoviePlayback";
NSString* const AVAudioSessionModeVideoChat = @"AVAudioSessionModeVideoChat";
NSString* const AVAudioSessionModeSpokenAudio = @"AVAudioSessionModeSpokenAudio";
NSString* const AVAudioSessionInterruptionTypeKey = @"AVAudioSessionInterruptionTypeKey";
NSString* const AVAudioSessionInterruptionOptionKey = @"AVAudioSessionInterruptionOptionKey";
NSString* const AVAudioSessionRouteChangeReasonKey = @"AVAudioSessionRouteChangeReasonKey";
NSString* const AVAudioSessionRouteChangePreviousRouteKey = @"AVAudioSessionRouteChangePreviousRouteKey";
NSString* const AVAudioSessionSilenceSecondaryAudioHintTypeKey = @"AVAudioSessionSilenceSecondaryAudioHintTypeKey";

NSString* const AVAudioSessionInterruptionNotification = @"AVAudioSessionInterruptionNotification";
NSString* const AVAudioSessionRouteChangeNotification = @"AVAudioSessionRouteChangeNotification";
NSString* const AVAudioSessionMediaServicesWereLostNotification = @"AVAudioSessionMediaServicesWereLostNotification";
NSString* const AVAudioSessionMediaServicesWereResetNotification = @"AVAudioSessionMediaServicesWereResetNotification";
NSString* const AVAudioSessionSilenceSecondaryAudioHintNotification = @"AVAudioSessionSilenceSecondaryAudioHintNotification";

@implementation AVAudioSession
/**
@Status Stub
@Notes
*/
+ (AVAudioSession*)sharedInstance {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)requestRecordPermission:(PermissionBlock)response {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (AVAudioSessionRecordPermission)recordPermission {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setCategory:(NSString*)theCategory error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setCategory:(NSString*)category withOptions:(AVAudioSessionCategoryOptions)options error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setMode:(NSString*)theMode error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setActive:(BOOL)beActive error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setActive:(BOOL)active withOptions:(AVAudioSessionSetActiveOptions)options error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setInputGain:(float)gain error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setPreferredSampleRate:(double)sampleRate error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setPreferredIOBufferDuration:(NSTimeInterval)duration error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setPreferredInputNumberOfChannels:(NSInteger)count error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setPreferredOutputNumberOfChannels:(NSInteger)count error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)overrideOutputAudioPort:(AVAudioSessionPortOverride)portOverride error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setPreferredInput:(AVAudioSessionPortDescription*)inPort error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setInputDataSource:(AVAudioSessionDataSourceDescription*)dataSource error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setOutputDataSource:(AVAudioSessionDataSourceDescription*)dataSource error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setPreferredHardwareSampleRate:(double)sampleRate error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setActive:(BOOL)beActive withFlags:(NSInteger)flags error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
