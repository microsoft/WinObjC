//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <MediaPlayer/MediaPlayerExport.h>
#import <Foundation/NSObject.h>
#import <MediaPlayer/MPMediaPlayback.h>
#import <CoreGraphics/CGBase.h>

@class NSString;
@class NSURL;
@class UIView;
@class NSArray;
@class NSError;
@class UIImage;
@class MPMovieAccessLog;
@class MPMovieErrorLog;
@class UIColor;

typedef NS_ENUM(NSUInteger, MPMovieScalingMode) {
    MPMovieScalingModeNone,
    MPMovieScalingModeAspectFit,
    MPMovieScalingModeAspectFill,
    MPMovieScalingModeFill
};

typedef NS_ENUM(NSUInteger, MPMovieControlMode) { MPMovieControlModeDefault, MPMovieControlModeVolumeOnly, MPMovieControlModeHidden };

typedef NS_ENUM(NSUInteger, MPMovieLoadState) {
    MPMovieLoadStateUnknown = 0,
    MPMovieLoadStatePlayable = 1 << 0,
    MPMovieLoadStatePlaythroughOK = 1 << 1,
    MPMovieLoadStateStalled = 1 << 2,
};

typedef NS_ENUM(NSUInteger, MPMovieControlStyle) {
    MPMovieControlStyleNone,
    MPMovieControlStyleEmbedded,
    MPMovieControlStyleFullscreen,
    MPMovieControlStyleDefault = MPMovieControlStyleFullscreen
};

typedef NS_ENUM(NSUInteger, MPMovieFinishReason) {
    MPMovieFinishReasonPlaybackEnded,
    MPMovieFinishReasonPlaybackError,
    MPMovieFinishReasonUserExited
};

typedef NS_ENUM(NSUInteger, MPMoviePlaybackState) {
    MPMoviePlaybackStateStopped,
    MPMoviePlaybackStatePlaying,
    MPMoviePlaybackStatePaused,
    MPMoviePlaybackStateInterrupted,
    MPMoviePlaybackStateSeekingForward,
    MPMoviePlaybackStateSeekingBackward
};

typedef NS_ENUM(NSUInteger, MPMovieRepeatMode) { MPMovieRepeatModeNone, MPMovieRepeatModeOne };

typedef NS_OPTIONS(NSUInteger, MPMovieTimeOption) { MPMovieTimeOptionNearestKeyFrame, MPMovieTimeOptionExact };

typedef NS_ENUM(NSUInteger, MPMovieMediaTypeMask) {
    MPMovieMediaTypeMaskNone = 0,
    MPMovieMediaTypeMaskVideo = 1 << 0,
    MPMovieMediaTypeMaskAudio = 1 << 1
};

typedef NS_ENUM(NSUInteger, MPMovieSourceType) { MPMovieSourceTypeUnknown, MPMovieSourceTypeFile, MPMovieSourceTypeStreaming };

MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerThumbnailImageKey;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerThumbnailTimeKey;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerThumbnailErrorKey;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerFullscreenAnimationDurationUserInfoKey;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerFullscreenAnimationCurveUserInfoKey;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerPlaybackDidFinishReasonUserInfoKey;

MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerWillExitFullscreenNotification;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerDidExitFullscreenNotification;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerWillEnterFullscreenNotification;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerDidEnterFullscreenNotification;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerPlaybackDidFinishNotification;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerLoadStateDidChangeNotification;

MEDIAPLAYER_EXPORT_CLASS

@interface MPMoviePlayerController : NSObject <MPMediaPlayback>
@property (copy, nonatomic) NSURL* contentURL STUB_PROPERTY;
@property (nonatomic) MPMovieSourceType movieSourceType STUB_PROPERTY;
@property (readonly, nonatomic) MPMovieMediaTypeMask movieMediaTypes STUB_PROPERTY;
@property (nonatomic) BOOL allowsAirPlay STUB_PROPERTY;
@property (readonly, getter=isAirPlayVideoActive, nonatomic) BOOL airPlayVideoActive STUB_PROPERTY;
@property (readonly, nonatomic) CGSize naturalSize STUB_PROPERTY;
@property (getter=isFullscreen, nonatomic) BOOL fullscreen STUB_PROPERTY;
@property (nonatomic) MPMovieScalingMode scalingMode STUB_PROPERTY;
@property (nonatomic) MPMovieControlStyle controlStyle STUB_PROPERTY;
@property (nonatomic) BOOL useApplicationAudioSession STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval duration STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval playableDuration STUB_PROPERTY;
@property (readonly, nonatomic) UIView* view STUB_PROPERTY;
@property (readonly, nonatomic) UIView* backgroundView STUB_PROPERTY;
@property (readonly, nonatomic) MPMovieLoadState loadState STUB_PROPERTY;
@property (readonly, nonatomic) MPMoviePlaybackState playbackState STUB_PROPERTY;
@property (nonatomic) NSTimeInterval initialPlaybackTime STUB_PROPERTY;
@property (nonatomic) NSTimeInterval endPlaybackTime STUB_PROPERTY;
@property (nonatomic) BOOL shouldAutoplay STUB_PROPERTY;
@property (readonly, nonatomic) BOOL readyForDisplay STUB_PROPERTY;
@property (nonatomic) MPMovieRepeatMode repeatMode STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* timedMetadata STUB_PROPERTY;
@property (readonly, nonatomic) MPMovieAccessLog* accessLog STUB_PROPERTY;
@property (readonly, nonatomic) MPMovieErrorLog* errorLog STUB_PROPERTY;

@property (nonatomic, readonly) BOOL isPreparedToPlay STUB_PROPERTY;
@property (nonatomic) float currentPlaybackRate STUB_PROPERTY;
@property (nonatomic) NSTimeInterval currentPlaybackTime STUB_PROPERTY;

- (instancetype)initWithContentURL:(NSURL*)url STUB_METHOD;
- (void)setFullscreen:(BOOL)fullscreen animated:(BOOL)animated STUB_METHOD;
- (void)playPrerollAdWithCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (UIImage*)thumbnailImageAtTime:(NSTimeInterval)playbackTime timeOption:(MPMovieTimeOption)option STUB_METHOD;
- (void)requestThumbnailImagesAtTimes:(NSArray*)playbackTimes timeOption:(MPMovieTimeOption)option STUB_METHOD;
- (void)cancelAllThumbnailImageRequests STUB_METHOD;
- (UIColor*)backgroundColor STUB_METHOD;
- (MPMovieControlMode)movieControlMode STUB_METHOD;

@end
