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

NSString* const AVPlayerItemFailedToPlayToEndTimeErrorKey = @"AVPlayerItemFailedToPlayToEndTimeErrorKey";

NSString* const AVPlayerItemDidPlayToEndTimeNotification = @"AVPlayerItemDidPlayToEndTimeNotification";
NSString* const AVPlayerItemFailedToPlayToEndTimeNotification = @"AVPlayerItemFailedToPlayToEndTimeNotification";
NSString* const AVPlayerItemTimeJumpedNotification = @"AVPlayerItemTimeJumpedNotification";
NSString* const AVPlayerItemPlaybackStalledNotification = @"AVPlayerItemPlaybackStalledNotification";
NSString* const AVPlayerItemNewAccessLogEntryNotification = @"AVPlayerItemNewAccessLogEntryNotification";
NSString* const AVPlayerItemNewErrorLogEntryNotification = @"AVPlayerItemNewErrorLogEntryNotification";

@implementation AVPlayerItem
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
+ (AVPlayerItem*)playerItemWithURL:(NSURL*)URL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithAsset:(AVAsset*)asset {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (AVPlayerItem*)playerItemWithAsset:(AVAsset*)asset {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithAsset:(AVAsset*)asset automaticallyLoadedAssetKeys:(NSArray*)automaticallyLoadedAssetKeys {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (AVPlayerItem*)playerItemWithAsset:(AVAsset*)asset automaticallyLoadedAssetKeys:(NSArray*)automaticallyLoadedAssetKeys {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)stepByCount:(NSInteger)stepCount {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)seekToDate:(NSDate*)date {
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
- (void)seekToTime:(CMTime)time completionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)seekToDate:(NSDate*)date completionHandler:(void (^)(BOOL))completionHandler {
    UNIMPLEMENTED();
    return StubReturn();
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
- (void)cancelPendingSeeks {
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
- (NSDate*)currentDate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (AVPlayerItemAccessLog*)accessLog {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (AVPlayerItemErrorLog*)errorLog {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)selectMediaOption:(AVMediaSelectionOption*)mediaSelectionOption inMediaSelectionGroup:(AVMediaSelectionGroup*)mediaSelectionGroup {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (AVMediaSelectionOption*)selectedMediaOptionInMediaSelectionGroup:(AVMediaSelectionGroup*)mediaSelectionGroup {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)selectMediaOptionAutomaticallyInMediaSelectionGroup:(AVMediaSelectionGroup*)mediaSelectionGroup {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)addOutput:(AVPlayerItemOutput*)output {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)removeOutput:(AVPlayerItemOutput*)output {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
