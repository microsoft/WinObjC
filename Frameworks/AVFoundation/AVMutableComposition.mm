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

@implementation AVMutableComposition
/**
@Status Stub
@Notes
*/
- (void)insertEmptyTimeRange:(CMTimeRange)timeRange {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)insertTimeRange:(CMTimeRange)timeRange ofAsset:(AVAsset*)asset atTime:(CMTime)startTime error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)removeTimeRange:(CMTimeRange)timeRange {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)scaleTimeRange:(CMTimeRange)timeRange toDuration:(CMTime)duration {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
+ (instancetype)composition {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (AVMutableCompositionTrack*)addMutableTrackWithMediaType:(NSString*)mediaType preferredTrackID:(CMPersistentTrackID)preferredTrackID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)removeTrack:(AVCompositionTrack*)track {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (AVMutableCompositionTrack*)mutableTrackCompatibleWithTrack:(AVAssetTrack*)track {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
