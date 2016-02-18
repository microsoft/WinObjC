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

#import <StubReturn.h>
#import <MediaPlayer/MPMoviePlayerController.h>

NSString* const MPMoviePlayerThumbnailImageKey = @"MPMoviePlayerThumbnailImageKey";
NSString* const MPMoviePlayerThumbnailTimeKey = @"MPMoviePlayerThumbnailTimeKey";
NSString* const MPMoviePlayerThumbnailErrorKey = @"MPMoviePlayerThumbnailErrorKey";
NSString* const MPMoviePlayerFullscreenAnimationDurationUserInfoKey = @"MPMoviePlayerFullscreenAnimationDurationUserInfoKey";
NSString* const MPMoviePlayerFullscreenAnimationCurveUserInfoKey = @"MPMoviePlayerFullscreenAnimationCurveUserInfoKey";
NSString* const MPMoviePlayerPlaybackDidFinishReasonUserInfoKey = @"MPMoviePlayerPlaybackDidFinishReasonUserInfoKey";

NSString* const MPMoviePlayerWillExitFullscreenNotification = @"MPMoviePlayerWillExitFullscreenNotification";
NSString* const MPMoviePlayerDidExitFullscreenNotification = @"MPMoviePlayerDidExitFullscreenNotification";
NSString* const MPMoviePlayerWillEnterFullscreenNotification = @"MPMoviePlayerWillEnterFullscreenNotification";
NSString* const MPMoviePlayerDidEnterFullscreenNotification = @"MPMoviePlayerDidEnterFullscreenNotification";
NSString* const MPMoviePlayerPlaybackDidFinishNotification = @"MPMoviePlayerPlaybackDidFinishNotification";
NSString* const MPMoviePlayerLoadStateDidChangeNotification = @"MPMoviePlayerLoadStateDidChangeNotification";

@implementation MPMoviePlayerController
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithContentURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setFullscreen:(BOOL)fullscreen animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)playPrerollAdWithCompletionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (UIImage*)thumbnailImageAtTime:(NSTimeInterval)playbackTime timeOption:(MPMovieTimeOption)option {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)requestThumbnailImagesAtTimes:(NSArray*)playbackTimes timeOption:(MPMovieTimeOption)option {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)cancelAllThumbnailImageRequests {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (UIColor*)backgroundColor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (MPMovieControlMode)movieControlMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)play {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)pause {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stop {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)prepareToPlay {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)beginSeekingBackward {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)beginSeekingForward {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)endSeeking {
    UNIMPLEMENTED();
}

@end
