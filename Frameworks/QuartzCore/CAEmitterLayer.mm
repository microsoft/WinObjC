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

#include "Starboard.h"
#include "QuartzCore/CAEmitterLayer.h"
#include "CAEmitterCellInternal.h"

NSString* const kCAEmitterLayerPoint = @"kCAEmitterLayerPoint";
NSString* const kCAEmitterLayerLine = @"kCAEmitterLayerLine";
NSString* const kCAEmitterLayerRectangle = @"kCAEmitterLayerRectangle";
NSString* const kCAEmitterLayerCuboid = @"kCAEmitterLayerCuboid";
NSString* const kCAEmitterLayerCircle = @"kCAEmitterLayerCircle";
NSString* const kCAEmitterLayerSphere = @"kCAEmitterLayerSphere";
NSString* const kCAEmitterLayerPoints = @"kCAEmitterLayerPoints";
NSString* const kCAEmitterLayerOutline = @"kCAEmitterLayerOutline";
NSString* const kCAEmitterLayerSurface = @"kCAEmitterLayerSurface";
NSString* const kCAEmitterLayerVolume = @"kCAEmitterLayerVolume";
NSString* const kCAEmitterLayerUnordered = @"kCAEmitterLayerUnordered";
NSString* const kCAEmitterLayerOldestFirst = @"kCAEmitterLayerOldestFirst";
NSString* const kCAEmitterLayerOldestLast = @"kCAEmitterLayerOldestLast";
NSString* const kCAEmitterLayerBackToFront = @"kCAEmitterLayerBackToFront";
NSString* const kCAEmitterLayerAdditive = @"kCAEmitterLayerAdditive";

// TODO improve performance and change the replay time to 1 second.
@implementation CAEmitterLayer {
    idretaintype(NSArray) _emitterCells;
    idretaintype(NSTimer) _replayTimer;
}

- (void)generateCALayersFromEmitterCells:(NSTimer*)withTimer {
    if (_emitterCells == nil || self.hidden || self.superlayer == nil) {
        [self endReplayingEmitters];
        return;
    }
    NSUInteger count = [_emitterCells count];
    // Go through my emitter cells and add them to my subview.
    for (NSUInteger i = 0; i < count; i++) {
        CAEmitterCell* emitterCell = ((CAEmitterCell*)[_emitterCells objectAtIndex:i]);
        CALayer* ca = [emitterCell generateCALayerFromEmitterCell:_emitterPosition
                                             withParentOffsetLong:0
                                              withParentOffsetLat:0
                                                withParentCALayer:self
                                              withBabyEmitterCell:nil];

        [self addSublayer:ca];
    }
}

- (void)startReplayingEmitters {
    [self endReplayingEmitters];
    // Set to 2 seconds to reduce latency on low end devices.
    _replayTimer = [NSTimer scheduledTimerWithTimeInterval:2.0
                                                    target:self
                                                  selector:@selector(generateCALayersFromEmitterCells:)
                                                  userInfo:nil
                                                   repeats:YES];
}

- (void)endReplayingEmitters {
    if (_replayTimer != nil) {
        [_replayTimer invalidate];
        _replayTimer = nil;
    }
}

/**
 @Status Interoperable
*/
- (void)setEmitterCells:(NSArray*)emitterCells {
    _emitterCells = [NSArray arrayWithArray:emitterCells];

    [self generateCALayersFromEmitterCells:_replayTimer];
    [self setNeedsLayout];
    [self startReplayingEmitters];
}

/**
 @Status Interoperable
*/
- (NSArray*)emitterCells {
    return [[_emitterCells copy] autorelease];
}

@end
