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

@implementation AVMutableVideoCompositionLayerInstruction
/**
@Status Stub
@Notes
*/
+ (instancetype)videoCompositionLayerInstruction {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (instancetype)videoCompositionLayerInstructionWithAssetTrack:(AVAssetTrack*)track {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)setOpacity:(float)opacity atTime:(CMTime)time {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)setOpacityRampFromStartOpacity:(float)startOpacity toEndOpacity:(float)endOpacity timeRange:(CMTimeRange)timeRange {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)setTransform:(CGAffineTransform)transform atTime:(CMTime)time {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)setTransformRampFromStartTransform:(CGAffineTransform)startTransform
                            toEndTransform:(CGAffineTransform)endTransform
                                 timeRange:(CMTimeRange)timeRange {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)setCropRectangle:(CGRect)cropRectangle atTime:(CMTime)time {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)setCropRectangleRampFromStartCropRectangle:(CGRect)startCropRectangle
                                toEndCropRectangle:(CGRect)endCropRectangle
                                         timeRange:(CMTimeRange)timeRange {
    UNIMPLEMENTED();
}

@end
