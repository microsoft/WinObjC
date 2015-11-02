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

#ifndef _MPMOVIEPLAYERCONTROLLER_H_
#define _MPMOVIEPLAYERCONTROLLER_H_

typedef NS_ENUM(NSInteger, MPMovieLoadState) {
    MPMovieLoadStateUnknown = 0,
    MPMovieLoadStatePlayable = 1 << 0,
    MPMovieLoadStatePlaythroughOK = 1 << 1,
    MPMovieLoadStateStalled = 1 << 2,
};

typedef NS_ENUM(NSInteger, MPMovieControlStyle) {
    MPMovieControlStyleNone,
    MPMovieControlStyleEmbedded,
    MPMovieControlStyleFullscreen,
    MPMovieControlStyleDefault = MPMovieControlStyleFullscreen
};

typedef NS_ENUM(NSInteger, MPMovieFinishReason) {
    MPMovieFinishReasonPlaybackEnded,
    MPMovieFinishReasonPlaybackError,
    MPMovieFinishReasonUserExited
};

typedef NS_ENUM(NSInteger, MPMoviePlaybackState) {
    MPMoviePlaybackStateStopped,
    MPMoviePlaybackStatePlaying,
    MPMoviePlaybackStatePaused,
    MPMoviePlaybackStateInterrupted,
    MPMoviePlaybackStateSeekingForward,
    MPMoviePlaybackStateSeekingBackward
};

typedef NS_ENUM(NSInteger, MPMovieRepeatMode) { MPMovieRepeatModeNone, MPMovieRepeatModeOne };

typedef NS_ENUM(int, MPMovieScalingMode) {
    MPMovieScalingModeNone,
    MPMovieScalingModeAspectFit,
    MPMovieScalingModeAspectFill,
    MPMovieScalingModeFill
};

typedef NS_ENUM(NSInteger, MPMovieTimeOption) { MPMovieTimeOptionNearestKeyFrame, MPMovieTimeOptionExact };

typedef NS_ENUM(NSInteger, MPMovieMediaTypeMask) {
    MPMovieMediaTypeMaskNone = 0,
    MPMovieMediaTypeMaskVideo = 1 << 0,
    MPMovieMediaTypeMaskAudio = 1 << 1
};

typedef NS_ENUM(NSInteger, MPMovieSourceType) { MPMovieSourceTypeUnknown, MPMovieSourceTypeFile, MPMovieSourceTypeStreaming };

typedef NS_ENUM(int, MPMovieControlMode) { MPMovieControlModeDefault, MPMovieControlModeVolumeOnly, MPMovieControlModeHidden };

SB_EXPORT NSString* const MPMoviePlayerThumbnailImageKey;
SB_EXPORT NSString* const MPMoviePlayerThumbnailTimeKey;
SB_EXPORT NSString* const MPMoviePlayerThumbnailErrorKey;
SB_EXPORT NSString* const MPMoviePlayerFullscreenAnimationDurationUserInfoKey;
SB_EXPORT NSString* const MPMoviePlayerFullscreenAnimationCurveUserInfoKey;
SB_EXPORT NSString* const MPMoviePlayerPlaybackDidFinishReasonUserInfoKey;

SB_EXPORT NSString* const MPMoviePlayerWillExitFullscreenNotification;
SB_EXPORT NSString* const MPMoviePlayerDidExitFullscreenNotification;
SB_EXPORT NSString* const MPMoviePlayerWillEnterFullscreenNotification;
SB_EXPORT NSString* const MPMoviePlayerDidEnterFullscreenNotification;
SB_EXPORT NSString* const MPMoviePlayerPlaybackDidFinishNotification;
SB_EXPORT NSString* const MPMoviePlayerLoadStateDidChangeNotification;

@interface MPMovieErrorLogEvent : NSObject

@property (nonatomic, readonly) NSString* errorDomain;
@property (nonatomic, readonly) NSUInteger errorStatusCode;

@end

@interface MPMovieErrorLog : NSObject

@property (nonatomic, readonly) NSArray* events;

@end

@protocol MPMediaPlayback
@required
- (void)play;

@required
- (void)pause;

@required
- (void)stop;

@required
- (void)prepareToPlay;

@required
- (void)beginSeekingBackward;

@required
- (void)beginSeekingForward;

@required
- (void)endSeeking;

@required
@property (nonatomic, readonly) BOOL isPreparedToPlay;

@required
@property (nonatomic) float currentPlaybackRate;

@required
@property (nonatomic) NSTimeInterval currentPlaybackTime;
@end

@class MPMovieAccessLog;
@class MPMovieErrorLog;

@interface MPMoviePlayerController : NSObject <MPMediaPlayback, NSObject>

- (instancetype)initWithContentURL:(NSURL*)url;
- (void)setFullscreen:(BOOL)fullscreen animated:(BOOL)animated;
- (void)playPrerollAdWithCompletionHandler:(void (^)(NSError* error))completionHandler;
- (UIImage*)thumbnailImageAtTime:(NSTimeInterval)playbackTime timeOption:(MPMovieTimeOption)option;
- (void)requestThumbnailImagesAtTimes:(NSArray*)playbackTimes timeOption:(MPMovieTimeOption)option;
- (void)cancelAllThumbnailImageRequests;
- (UIColor*)backgroundColor;
- (MPMovieControlMode)movieControlMode;

@property (nonatomic, copy) NSURL* contentURL;
@property (nonatomic) MPMovieSourceType movieSourceType;
@property (nonatomic, readonly) MPMovieMediaTypeMask movieMediaTypes;
@property (nonatomic) BOOL allowsAirPlay;
@property (nonatomic, readonly, getter=isAirPlayVideoActive) BOOL airPlayVideoActive;
@property (nonatomic, readonly) CGSize naturalSize;
@property (nonatomic, getter=isFullscreen) BOOL fullscreen;
@property (nonatomic) MPMovieScalingMode scalingMode;
@property (nonatomic) MPMovieControlStyle controlStyle;
@property (nonatomic) BOOL useApplicationAudioSession;
@property (nonatomic, readonly) NSTimeInterval duration;
@property (nonatomic, readonly) NSTimeInterval playableDuration;
@property (nonatomic, readonly) UIView* view;
@property (nonatomic, readonly) UIView* backgroundView;
@property (nonatomic, readonly) MPMovieLoadState loadState;
@property (nonatomic, readonly) MPMoviePlaybackState playbackState;
@property (nonatomic) NSTimeInterval initialPlaybackTime;
@property (nonatomic) NSTimeInterval endPlaybackTime;
@property (nonatomic) BOOL shouldAutoplay;
@property (nonatomic, readonly) BOOL readyForDisplay;
@property (nonatomic) MPMovieRepeatMode repeatMode;
@property (nonatomic, readonly) NSArray* timedMetadata;
@property (nonatomic, readonly) MPMovieAccessLog* accessLog;
@property (nonatomic, readonly) MPMovieErrorLog* errorLog;

@end

#endif /* _MPMOVIEPLAYERCONTROLLER_H_ */