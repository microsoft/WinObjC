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

#import <UIKit/UIFieldBehavior.h>
#import <StubReturn.h>

@implementation UIFieldBehavior
/**
 @Status Stub
 @Notes
*/
+ (instancetype)dragField {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)springField {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)velocityFieldWithVector:(CGVector)direction {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)electricField {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)magneticField {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)radialGravityFieldWithPosition:(CGPoint)position {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)linearGravityFieldWithVector:(CGVector)direction {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)vortexField {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)noiseFieldWithSmoothness:(CGFloat)smoothness animationSpeed:(CGFloat)speed {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)turbulenceFieldWithSmoothness:(CGFloat)smoothness animationSpeed:(CGFloat)speed {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)fieldWithEvaluationBlock:(CGVector (^)(UIFieldBehavior*, CGPoint, CGVector, CGFloat, CGFloat, NSTimeInterval))block {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addItem:(id<UIDynamicItem>)item {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeItem:(id<UIDynamicItem>)item {
    UNIMPLEMENTED();
}

@end
