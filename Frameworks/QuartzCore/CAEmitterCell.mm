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

#import "QuartzCore/CAEmitterCell.h"
#import "CAEmitterCellInternal.h"
#import "QuartzCore/CATransform3D.h"
#import "Starboard.h"
#import <StubReturn.h>
#import <stdlib.h>

@interface CAEmitterCALayer : CALayer <CAMediaTiming, NSCoding, NSObject>
@property (strong) CAEmitterCell* birthedCell;
@property long animationCount;

@end

// Internal class soley used to save memory by erasing birthed CAEmitter cells.
@implementation CAEmitterCALayer

// dellocate all birthed CAEmitter cells when their animation finishes.
- (void)animationDidStop:(CAAnimation*)theAnimation finished:(BOOL)flag {
    // This is to prevent self from being released while locking on self.
    [self retain];
    theAnimation.delegate = nil;

    @synchronized(self) {
        _animationCount = _animationCount - 1;
        if (_animationCount == 0) {
            if (_birthedCell != nil) {
                [_birthedCell release];
                _birthedCell = nil;
            }
            [self removeAllAnimations];
            [self removeFromSuperlayer];
        }
    }
    [self release];
}

@end

// TODO enabled All color ranges and speeds, spin, spinRange, and all accelerations.
@implementation CAEmitterCell

@synthesize autoreverses;
@synthesize beginTime;
@synthesize duration;
@synthesize fillMode;
@synthesize repeatCount;
@synthesize repeatDuration;
@synthesize speed;
@synthesize timeOffset;
@synthesize yAcceleration = _yAcceleration;
@synthesize spin = _spin;
@synthesize redRange = _redRange;
@synthesize blueRange = _blueRange;
@synthesize greenRange = _greenRange;
@synthesize alphaRange = _alphaRange;
static const wchar_t* TAG = L"CAEmitterCell";
static const int MAX_BIRTHRATE = 100;
static const CGFloat epsilon = .000001f;

/**
 @Status Caveat
 @Notes Replay of a emitter cell is delayed to 2 seconds. Several properties have no effect. All color ranges and speeds have no effect,
 spin, spinRange, and all accelerations.
*/
+ (instancetype)emitterCell {
    return [[CAEmitterCell new] autorelease];
}

- (CGFloat)_calculateRandomSign {
    return (arc4random() % 2 ? 1 : -1);
}

// This function will not provide uniformly distributed numbers if range is above UINT32_MAX.
- (CGFloat)_randomNumberInRange:(CGFloat)range {
    return fmodf(arc4random(), range);
}

- (CGFloat)_randomNumberWithRandomSignInRange:(CGFloat)range {
    return [self _calculateRandomSign] * [self _randomNumberInRange:range];
}

- (CGFloat)_calculateRandomScale {
    CGFloat randomScale;
    if (_scaleRange > epsilon) {
        randomScale = [self _randomNumberWithRandomSignInRange:_scaleRange] + _scale;
    } else {
        randomScale = _scale;
    }

    return randomScale;
}

- (CABasicAnimation*)_calculateRandomScaleAnimation:(CGFloat)randomeScale withRandomLifetime:(CGFloat)lifetime {
    CABasicAnimation* internalScaleSpeedAnimation = [CABasicAnimation animationWithKeyPath:@"transform"];

    // Scale the content from RandomScale to RandomScale + _scaleSpeed for each duration to the end of the lifeTime.
    internalScaleSpeedAnimation.fromValue = [NSValue valueWithCATransform3D:CATransform3DMakeScale(randomeScale, randomeScale, 1)];
    internalScaleSpeedAnimation.toValue = [NSValue valueWithCATransform3D:CATransform3DMakeScale((randomeScale + (lifetime * _scaleSpeed)),
                                                                                                 (randomeScale + (lifetime * _scaleSpeed)),
                                                                                                 1)];

    internalScaleSpeedAnimation.beginTime = beginTime + CACurrentMediaTime();
    internalScaleSpeedAnimation.duration = lifetime;

    return internalScaleSpeedAnimation;
}

- (CGFloat)_calculateRandomLifetime {
    CGFloat randomLifetime = 0;
    if (_lifetimeRange > epsilon) {
        randomLifetime = [self _randomNumberWithRandomSignInRange:_lifetimeRange] + _lifetime;
    } else {
        randomLifetime = _lifetime;
    }
    return randomLifetime;
}

- (CGFloat)_calculateRandomVelocity {
    CGFloat randomVelocity;
    if (randomVelocity > epsilon) {
        randomVelocity = [self _randomNumberWithRandomSignInRange:_velocityRange] + _velocity;
    } else {
        randomVelocity = _velocity;
    }
    return randomVelocity;
}

- (CGRect)_calculateCGRect {
    float startingWidth = CGImageGetWidth(((CGImageRef)_contents));
    float startingHeight = CGImageGetWidth(((CGImageRef)_contents));
    return CGRectMake(startingWidth * _contentsRect.origin.x,
                      startingHeight * _contentsRect.origin.y,
                      startingWidth * _contentsRect.size.width,
                      startingHeight * _contentsRect.size.height);
}

- (CGPoint)_calculatePosition:(CGPoint)startingPosition
                withLongitude:(CGFloat)randomEmissionRangeLong
                 withLatitude:(CGFloat)randomEmissionRangeLat
                 withVelocity:(CGFloat)velocity
                 withlifeTime:(CGFloat)lifetime {
    CGFloat randomLong = randomEmissionRangeLong + _emissionLongitude;
    CGFloat randomLat = randomEmissionRangeLat + _emissionLatitude;

    CGFloat flattenedY = sinf(randomLong) * cosf(randomLat);
    CGFloat flattenedX = cosf(randomLong) * cosf(randomLat);

    CGFloat distance = velocity * lifetime;
    CGFloat randomEmittedY = startingPosition.y + (distance * flattenedY);
    CGFloat randomEmittedX = startingPosition.x + (distance * flattenedX);

    return CGPointMake(randomEmittedX, randomEmittedY);
}

- (CAEmitterCALayer*)generateCALayerFromEmitterCell:(CGPoint)startingPosition
                               withParentOffsetLong:(CGFloat)offsetLong
                                withParentOffsetLat:(CGFloat)offsetLat
                                  withParentCALayer:(CALayer*)parent
                                withBabyEmitterCell:(CAEmitterCell*)babyCell {
    // If the cell is not enabled we currently disable it as well as its children cells.
    if (!_enabled) {
        return nil;
    }

    CABasicAnimation* internalPositionAnimation = [CABasicAnimation animationWithKeyPath:@"position"];

    // distance traveled
    CGFloat randomVelocity = [self _calculateRandomVelocity];
    CGFloat randomLifetime = [self _calculateRandomLifetime];
    CGFloat distance = randomVelocity * randomLifetime;

    // Each emitter cell maps to a CAEmitterCALayer
    CAEmitterCALayer* internalLayer = [CAEmitterCALayer new];
    internalLayer.birthedCell = babyCell;
    internalLayer.contents = _contents;
    internalLayer.frame = [self _calculateCGRect];

    // Total animations that need to finish before releasing.
    long animationCount = 0;

    // Add the scale animation
    CGFloat randomScale = [self _calculateRandomScale];
    if ((fabs(randomScale) > epsilon) && ((fabs(randomScale) > (epsilon + 1.0f)) || (fabs(randomScale) < (1.0f - epsilon)))) {
        CABasicAnimation* randomeScaleAnimation = [self _calculateRandomScaleAnimation:randomScale withRandomLifetime:randomLifetime];
        randomeScaleAnimation.delegate = internalLayer;
        [internalLayer addAnimation:randomeScaleAnimation forKey:nil];
        animationCount++;
    }

    // Calculation the destination of the cell and add the animation to the layer.
    CGFloat randomEmissionRangeLat = 0;
    CGFloat randomEmissionRangeLong = 0;
    if (fabs(_emissionRange) > epsilon) {
        randomEmissionRangeLat = [self _randomNumberWithRandomSignInRange:(fabs(_emissionRange))] + offsetLat;
        randomEmissionRangeLong = [self _randomNumberWithRandomSignInRange:(fabs(_emissionRange))] + offsetLong;
    }

    CGPoint destination = [self _calculatePosition:startingPosition
                                     withLongitude:randomEmissionRangeLong
                                      withLatitude:randomEmissionRangeLat
                                      withVelocity:randomVelocity
                                      withlifeTime:randomLifetime];

    internalPositionAnimation.fromValue = [NSValue valueWithCGPoint:startingPosition];
    internalPositionAnimation.toValue = [NSValue valueWithCGPoint:destination];
    internalPositionAnimation.beginTime = CACurrentMediaTime() + beginTime;
    internalPositionAnimation.duration = randomLifetime;
    internalPositionAnimation.delegate = internalLayer;
    [internalLayer addAnimation:internalPositionAnimation forKey:nil];
    animationCount++;

    // Init children emitter cells, emitter cells contained in this emittercells arraylist
    if (_emitterCells != nil && [_emitterCells count] > 0) {
        for (NSUInteger i = 0; i < [_emitterCells count]; ++i) {
            CAEmitterCell* emitterCell = ((CAEmitterCell*)[_emitterCells objectAtIndex:i]);

            CGPoint _calculatedStartingPoint = [self _calculatePosition:startingPosition
                                                          withLongitude:randomEmissionRangeLong
                                                           withLatitude:randomEmissionRangeLat
                                                           withVelocity:randomVelocity
                                                           withlifeTime:emitterCell.beginTime];

            CALayer* emitterCellLayer = [emitterCell generateCALayerFromEmitterCell:_calculatedStartingPoint
                                                               withParentOffsetLong:_emissionLongitude
                                                                withParentOffsetLat:_emissionLatitude
                                                                  withParentCALayer:(CALayer*)parent
                                                                withBabyEmitterCell:nil];
            [parent addSublayer:emitterCellLayer];
        }
    }

    // Creates birthrate number of emittercells from this cell.
    if (_birthRate > 1) {
        // Birthrate is capped due to the memory impact of the current implementation.
        if (_birthRate > MAX_BIRTHRATE) {
            _birthRate = MAX_BIRTHRATE;
        }

        for (NSUInteger i = (_birthRate - 1); i > 0; --i) {
            // birthrate is number of children emitted per second, we divide up a second and emit cells evenly over the second.
            NSString* babyName = [NSString stringWithFormat:@"%i _", i];
            if (_name != nil) {
                babyName = [babyName stringByAppendingString:_name];
            }
            CAEmitterCell* babyCell = [self initBirthedCell:((60.0f + i) / ((_birthRate - 1.0f) * MAX_BIRTHRATE)) withName:babyName];
            CALayer* ca = [babyCell generateCALayerFromEmitterCell:startingPosition
                                              withParentOffsetLong:offsetLong
                                               withParentOffsetLat:offsetLat
                                                 withParentCALayer:(CALayer*)parent
                                               withBabyEmitterCell:babyCell];

            [parent addSublayer:ca];
        }
    }

    internalLayer.animationCount = animationCount;
    return [internalLayer autorelease];
}

- (instancetype)init {
    if (self = [super init]) {
        _contentsRect = CGRectMake(0.0, 0.0, 1.0, 1.0);
        _scale = 1.0f;
        _velocity = 1.0f;
        _enabled = YES;
        _birthed = NO;
    }

    return self;
}

// A birthed cell is a cell created by an emitter cell and is assigned similar values from that emitterCell
- (CAEmitterCell*)initBirthedCell:(CGFloat)startOffset withName:(NSString*)babyName {
    CAEmitterCell* birthedCell = [[CAEmitterCell emitterCell] retain];
    birthedCell.contents = _contents;
    birthedCell.birthRate = 1; // This implementation does not allow children to give birth.
    birthedCell.birthed = YES;
    birthedCell.velocity = _velocity;
    birthedCell.velocityRange = _velocityRange;
    birthedCell.lifetime = _lifetime;
    birthedCell.enabled = _enabled;
    birthedCell.beginTime = beginTime + startOffset;
    birthedCell.duration = duration;
    birthedCell.emissionRange = _emissionRange;
    birthedCell.emissionLongitude = _emissionLongitude;
    birthedCell.emissionLatitude = _emissionLatitude;
    birthedCell.scale = _scale;
    birthedCell.scaleSpeed = _scaleSpeed;
    birthedCell.contentsRect = _contentsRect;
    birthedCell.name = babyName;
    return birthedCell;
}

/**
 @Status Stub
*/
- (BOOL)shouldArchiveValueForKey:(NSString*)key {
    return NO;
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (id)defaultValueForKey:(NSString*)key {
    return nil;
}

/**
 @Status Caveat
 @Notes Setting the property doesn't take effect.
*/
- (void)setYAcceleration:(float)acceleration {
    _yAcceleration = acceleration;
}

/**
 @Status Interoperable
*/
- (float)yAcceleration {
    return _yAcceleration;
}

/**
 @Status Caveat
 @Notes Setting the property doesn't take effect.
*/
- (void)setSpin:(float)spin {
    _spin = spin;
}

/**
 @Status Interoperable
*/
- (float)spin {
    return _spin;
}

/**
 @Status Caveat
 @Notes Setting the property doesn't take effect.
*/
- (void)setRedRange:(float)range {
    _redRange = range;
}

/**
 @Status Interoperable
*/
- (float)redRange {
    return _redRange;
}

/**
 @Status Caveat
 @Notes Setting the property doesn't take effect.
*/
- (void)setBlueRange:(float)range {
    _blueRange = range;
}

/**
 @Status Interoperable
*/
- (float)blueRange {
    return _blueRange;
}

/**
 @Status Caveat
 @Notes Setting the property doesn't take effect.
*/
- (void)setGreenRange:(float)range {
    _greenRange = range;
}

/**
 @Status Interoperable
*/
- (float)greenRange {
    return _greenRange;
}

/**
 @Status Caveat
 @Notes Setting the property doesn't take effect.
*/
- (void)setAlphaRange:(float)range {
    _alphaRange = range;
}

/**
 @Status Interoperable
*/
- (float)alphaRange {
    return _alphaRange;
}

@end
