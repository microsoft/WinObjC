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
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMSync.h>

@class AVPlayerItem;
@class NSURL;
@class NSDate;
@class NSString;
@class NSArray;
@class NSError;
@class AVPlayerMediaSelectionCriteria;

typedef NSInteger AVPlayerStatus;
typedef NSInteger AVPlayerActionAtItemEnd;
enum { AVPlayerStatusUnknown, AVPlayerStatusReadyToPlay, AVPlayerStatusFailed };
enum {
    AVPlayerActionAtItemEndAdvance = 0,
    AVPlayerActionAtItemEndPause = 1,
    AVPlayerActionAtItemEndNone = 2,
};

AVFOUNDATION_EXPORT_CLASS
@interface AVPlayer : NSObject
- (instancetype)initWithURL:(NSURL*)URL STUB_METHOD;
+ (instancetype)playerWithURL:(NSURL*)URL STUB_METHOD;
- (instancetype)initWithPlayerItem:(AVPlayerItem*)item STUB_METHOD;
+ (instancetype)playerWithPlayerItem:(AVPlayerItem*)item STUB_METHOD;
- (void)play STUB_METHOD;
- (void)pause STUB_METHOD;
@property (nonatomic) float rate STUB_PROPERTY;
@property (nonatomic) AVPlayerActionAtItemEnd actionAtItemEnd STUB_PROPERTY;
- (void)replaceCurrentItemWithPlayerItem:(AVPlayerItem*)item STUB_METHOD;
- (void)prerollAtRate:(float)rate completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (void)cancelPendingPrerolls STUB_METHOD;
- (CMTime)currentTime STUB_METHOD;
- (void)seekToTime:(CMTime)time STUB_METHOD;
- (void)seekToDate:(NSDate*)date STUB_METHOD;
- (void)seekToTime:(CMTime)time completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (void)seekToDate:(NSDate*)date completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (void)seekToTime:(CMTime)time toleranceBefore:(CMTime)toleranceBefore toleranceAfter:(CMTime)toleranceAfter STUB_METHOD;
- (void)seekToTime:(CMTime)time
   toleranceBefore:(CMTime)toleranceBefore
    toleranceAfter:(CMTime)toleranceAfter
 completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
@property (nonatomic) BOOL allowsExternalPlayback STUB_PROPERTY;
@property (readonly, getter=isExternalPlaybackActive, nonatomic) BOOL externalPlaybackActive STUB_PROPERTY;
@property (nonatomic) BOOL usesExternalPlaybackWhileExternalScreenIsActive STUB_PROPERTY;
@property (copy, nonatomic) NSString* externalPlaybackVideoGravity STUB_PROPERTY;
- (void)setRate:(float)rate time:(CMTime)itemTime atHostTime:(CMTime)hostClockTime STUB_METHOD;
@property (nonatomic) CMClockRef masterClock STUB_PROPERTY; // removed retain from this line as it causes an error
- (id)addPeriodicTimeObserverForInterval:(CMTime)interval queue:(dispatch_queue_t)queue usingBlock:(void (^)(CMTime))block STUB_METHOD;
- (id)addBoundaryTimeObserverForTimes:(NSArray*)times queue:(dispatch_queue_t)queue usingBlock:(void (^)(void))block STUB_METHOD;
- (void)removeTimeObserver:(id)observer STUB_METHOD;
@property (getter=isClosedCaptionDisplayEnabled, nonatomic) BOOL closedCaptionDisplayEnabled STUB_PROPERTY;
@property (getter=isMuted, nonatomic) BOOL muted STUB_PROPERTY;
@property (nonatomic) float volume STUB_PROPERTY;
@property (readonly, nonatomic) AVPlayerStatus status STUB_PROPERTY;
@property (readonly, nonatomic) NSError* error STUB_PROPERTY;
@property (readonly, nonatomic) AVPlayerItem* currentItem STUB_PROPERTY;
@property (readonly, nonatomic) BOOL outputObscuredDueToInsufficientExternalProtection STUB_PROPERTY;
@property (readonly, getter=isAirPlayVideoActive, nonatomic) BOOL airPlayVideoActive STUB_PROPERTY;
@property (nonatomic) BOOL allowsAirPlayVideo STUB_PROPERTY;
@property (nonatomic) BOOL usesAirPlayVideoWhileAirPlayScreenIsActive STUB_PROPERTY;
@property (nonatomic) BOOL appliesMediaSelectionCriteriaAutomatically STUB_PROPERTY;
- (AVPlayerMediaSelectionCriteria*)mediaSelectionCriteriaForMediaCharacteristic:(NSString*)mediaCharacteristic STUB_METHOD;
- (void)setMediaSelectionCriteria:(AVPlayerMediaSelectionCriteria*)criteria
           forMediaCharacteristic:(NSString*)mediaCharacteristic STUB_METHOD;
@end
