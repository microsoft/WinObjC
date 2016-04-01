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

@implementation AVPlayer
/**
@Status Stub
@Notes
*/
- (instancetype)initWithURL:(NSURL*)URL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (instancetype)playerWithURL:(NSURL*)URL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithPlayerItem:(AVPlayerItem*)item {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (instancetype)playerWithPlayerItem:(AVPlayerItem*)item {
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
- (void)replaceCurrentItemWithPlayerItem:(AVPlayerItem*)item {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)prerollAtRate:(float)rate completionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)cancelPendingPrerolls {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (CMTime)currentTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)seekToTime:(CMTime)time {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)seekToDate:(NSDate*)date {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)seekToTime:(CMTime)time completionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)seekToDate:(NSDate*)date completionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)seekToTime:(CMTime)time toleranceBefore:(CMTime)toleranceBefore toleranceAfter:(CMTime)toleranceAfter {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)seekToTime:(CMTime)time
   toleranceBefore:(CMTime)toleranceBefore
    toleranceAfter:(CMTime)toleranceAfter
 completionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)setRate:(float)rate time:(CMTime)itemTime atHostTime:(CMTime)hostClockTime {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (id)addPeriodicTimeObserverForInterval:(CMTime)interval queue:(dispatch_queue_t)queue usingBlock:(void (^)(CMTime))block {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (id)addBoundaryTimeObserverForTimes:(NSArray*)times queue:(dispatch_queue_t)queue usingBlock:(void (^)(void))block {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)removeTimeObserver:(id)observer {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (AVPlayerMediaSelectionCriteria*)mediaSelectionCriteriaForMediaCharacteristic:(NSString*)mediaCharacteristic {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)setMediaSelectionCriteria:(AVPlayerMediaSelectionCriteria*)criteria forMediaCharacteristic:(NSString*)mediaCharacteristic {
    UNIMPLEMENTED();
}

@end
