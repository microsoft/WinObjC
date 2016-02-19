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

#import <AVFoundation/AVFoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSArray;
@class NSError;
@class AVAudioSessionRouteDescription;
@class AVAudioSessionPortDescription;
@class AVAudioSessionDataSourceDescription;
@protocol AVAudioSessionDelegate;

typedef void (^PermissionBlock)(BOOL granted);
typedef NSUInteger AVAudioSessionCategoryOptions;
typedef NSUInteger AVAudioSessionInterruptionOptions;
typedef NSUInteger AVAudioSessionSetActiveOptions;
typedef NSUInteger AVAudioSessionPortOverride;
typedef NSUInteger AVAudioSessionRouteChangeReason;
typedef NSUInteger AVAudioSessionInterruptionType;
typedef NSInteger AVAudioSessionErrorCode;
typedef NSUInteger AVAudioSessionRecordPermission;
typedef NSUInteger AVAudioSessionSilenceSecondaryAudioHintType;
enum {
    AVAudioSessionCategoryOptionMixWithOthers = 0x1,
    AVAudioSessionCategoryOptionDuckOthers = 0x2,
    AVAudioSessionCategoryOptionAllowBluetooth = 0x4,
    AVAudioSessionCategoryOptionDefaultToSpeaker = 0x8,
    AVAudioSessionCategoryOptionInterruptSpokenAudioAndMixWithOthers = 0x11
};
enum { AVAudioSessionInterruptionOptionShouldResume = 1 };
enum { AVAudioSessionSetActiveOptionNotifyOthersOnDeactivation = 1 };
enum { AVAudioSessionPortOverrideNone = 0, AVAudioSessionPortOverrideSpeaker = 'spkr' };
enum {
    AVAudioSessionRouteChangeReasonUnknown = 0,
    AVAudioSessionRouteChangeReasonNewDeviceAvailable = 1,
    AVAudioSessionRouteChangeReasonOldDeviceUnavailable = 2,
    AVAudioSessionRouteChangeReasonCategoryChange = 3,
    AVAudioSessionRouteChangeReasonOverride = 4,
    AVAudioSessionRouteChangeReasonWakeFromSleep = 6,
    AVAudioSessionRouteChangeReasonNoSuitableRouteForCategory = 7,
    AVAudioSessionRouteChangeReasonRouteConfigurationChange = 8,
};
enum {
    AVAudioSessionInterruptionTypeBegan = 1,
    AVAudioSessionInterruptionTypeEnded = 0,
};
enum {
    AVAudioSessionRecordPermissionUndetermined = 'undt',
    AVAudioSessionRecordPermissionDenied = 'deny',
    AVAudioSessionRecordPermissionGranted = 'grnt'
};
enum { AVAudioSessionSilenceSecondaryAudioHintTypeBegin = 1, AVAudioSessionSilenceSecondaryAudioHintTypeEnd = 0 };
AVFOUNDATION_EXPORT NSString* const AVAudioSessionCategoryAmbient;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionCategorySoloAmbient;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionCategoryPlayback;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionCategoryRecord;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionCategoryPlayAndRecord;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionCategoryAudioProcessing;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionCategoryMultiRoute;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionModeDefault;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionModeVoiceChat;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionModeGameChat;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionModeVideoRecording;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionModeMeasurement;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionModeMoviePlayback;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionModeVideoChat;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionModeSpokenAudio;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionInterruptionTypeKey;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionInterruptionOptionKey;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionRouteChangeReasonKey;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionRouteChangePreviousRouteKey;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionSilenceSecondaryAudioHintTypeKey;
enum { AVAudioSessionInterruptionFlags_ShouldResume = 1 };
enum { AVAudioSessionSetActiveFlags_NotifyOthersOnDeactivation = 1 };
enum {
    AVAudioSessionErrorCodeNone = 0,
    AVAudioSessionErrorCodeMediaServicesFailed = 'msrv',
    AVAudioSessionErrorCodeIsBusy = '!act',
    AVAudioSessionErrorCodeIncompatibleCategory = '!cat',
    AVAudioSessionErrorCodeCannotInterruptOthers = '!int',
    AVAudioSessionErrorCodeMissingEntitlement = 'ent?',
    AVAudioSessionErrorCodeSiriIsRecording = 'siri',
    AVAudioSessionErrorCodeCannotStartPlaying = '!pla',
    AVAudioSessionErrorCodeCannotStartRecording = '!rec',
    AVAudioSessionErrorCodeBadParam = -50,
    AVAudioSessionErrorInsufficientPriority = '!pri',
    AVAudioSessionErrorCodeResourceNotAvailable = '!res',
    AVAudioSessionErrorCodeUnspecified = 'what'
};
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortBluetoothHFP;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortUSBAudio;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionPortCarAudio;

AVFOUNDATION_EXPORT NSString* const AVAudioSessionInterruptionNotification;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionRouteChangeNotification;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionMediaServicesWereLostNotification;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionMediaServicesWereResetNotification;
AVFOUNDATION_EXPORT NSString* const AVAudioSessionSilenceSecondaryAudioHintNotification;

AVFOUNDATION_EXPORT_CLASS
@interface AVAudioSession : NSObject
+ (AVAudioSession*)sharedInstance STUB_METHOD;
- (void)requestRecordPermission:(PermissionBlock)response STUB_METHOD;
- (AVAudioSessionRecordPermission)recordPermission STUB_METHOD;
@property (readonly) NSString* category STUB_PROPERTY;
@property (readonly) NSArray* availableCategories STUB_PROPERTY;
@property (readonly) AVAudioSessionCategoryOptions categoryOptions STUB_PROPERTY;
- (BOOL)setCategory:(NSString*)theCategory error:(NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)setCategory:(NSString*)category withOptions:(AVAudioSessionCategoryOptions)options error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) NSString* mode STUB_PROPERTY;
@property (readonly) NSArray* availableModes STUB_PROPERTY;
- (BOOL)setMode:(NSString*)theMode error:(NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)setActive:(BOOL)beActive error:(NSError* _Nullable*)outError STUB_METHOD;
- (BOOL)setActive:(BOOL)active withOptions:(AVAudioSessionSetActiveOptions)options error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) float outputVolume STUB_PROPERTY;
@property (readonly) float inputGain STUB_PROPERTY;
@property (readonly, getter=isInputGainSettable) BOOL inputGainSettable STUB_PROPERTY;
- (BOOL)setInputGain:(float)gain error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) NSTimeInterval inputLatency STUB_PROPERTY;
@property (readonly) NSTimeInterval outputLatency STUB_PROPERTY;
@property (readonly) double sampleRate STUB_PROPERTY;
@property (readonly) double preferredSampleRate STUB_PROPERTY;
- (BOOL)setPreferredSampleRate:(double)sampleRate error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) NSTimeInterval IOBufferDuration STUB_PROPERTY;
@property (readonly) NSTimeInterval preferredIOBufferDuration STUB_PROPERTY;
- (BOOL)setPreferredIOBufferDuration:(NSTimeInterval)duration error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) BOOL secondaryAudioShouldBeSilencedHint STUB_PROPERTY;
@property (readonly) NSInteger inputNumberOfChannels STUB_PROPERTY;
@property (readonly) NSInteger maximumInputNumberOfChannels STUB_PROPERTY;
@property (readonly) NSInteger preferredInputNumberOfChannels STUB_PROPERTY;
- (BOOL)setPreferredInputNumberOfChannels:(NSInteger)count error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) NSInteger outputNumberOfChannels STUB_PROPERTY;
@property (readonly) NSInteger maximumOutputNumberOfChannels STUB_PROPERTY;
@property (readonly) NSInteger preferredOutputNumberOfChannels STUB_PROPERTY;
- (BOOL)setPreferredOutputNumberOfChannels:(NSInteger)count error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) AVAudioSessionRouteDescription* currentRoute STUB_PROPERTY;
@property (readonly, getter=isInputAvailable) BOOL inputAvailable STUB_PROPERTY;
@property (readonly, getter=isOtherAudioPlaying) BOOL otherAudioPlaying STUB_PROPERTY;
- (BOOL)overrideOutputAudioPort:(AVAudioSessionPortOverride)portOverride error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) NSArray* availableInputs STUB_PROPERTY;
@property (readonly) AVAudioSessionPortDescription* preferredInput STUB_PROPERTY;
- (BOOL)setPreferredInput:(AVAudioSessionPortDescription*)inPort error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) NSArray* inputDataSources STUB_PROPERTY;
@property (readonly) AVAudioSessionDataSourceDescription* inputDataSource STUB_PROPERTY;
- (BOOL)setInputDataSource:(AVAudioSessionDataSourceDescription*)dataSource error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) NSArray* outputDataSources STUB_PROPERTY;
@property (readonly) AVAudioSessionDataSourceDescription* outputDataSource STUB_PROPERTY;
- (BOOL)setOutputDataSource:(AVAudioSessionDataSourceDescription*)dataSource error:(NSError* _Nullable*)outError STUB_METHOD;
@property (assign) id<AVAudioSessionDelegate> delegate STUB_PROPERTY;
@property (readonly) NSInteger currentHardwareInputNumberOfChannels STUB_PROPERTY;
@property (readonly) NSInteger currentHardwareOutputNumberOfChannels STUB_PROPERTY;
@property (readonly) double currentHardwareSampleRate STUB_PROPERTY;
@property (readonly) double preferredHardwareSampleRate STUB_PROPERTY;
- (BOOL)setPreferredHardwareSampleRate:(double)sampleRate error:(NSError* _Nullable*)outError STUB_METHOD;
@property (readonly) BOOL inputIsAvailable STUB_PROPERTY;
- (BOOL)setActive:(BOOL)beActive withFlags:(NSInteger)flags error:(NSError* _Nullable*)outError STUB_METHOD;
@end
