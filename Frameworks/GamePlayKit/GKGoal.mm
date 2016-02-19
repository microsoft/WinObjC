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

#import <GamePlayKit/GKGoal.h>

@implementation GKGoal
/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToSeekAgent:(GKAgent*)agent {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToFleeAgent:(GKAgent*)agent {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToReachTargetSpeed:(float)targetSpeed {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToWander:(float)speed {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToAvoidAgents:(NSArray*)agents maxPredictionTime:(NSTimeInterval)maxPredictionTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToAvoidObstacles:(NSArray*)obstacles maxPredictionTime:(NSTimeInterval)maxPredictionTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToInterceptAgent:(GKAgent*)target maxPredictionTime:(NSTimeInterval)maxPredictionTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToSeparateFromAgents:(NSArray*)agents maxDistance:(float)maxDistance maxAngle:(float)maxAngle {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToAlignWithAgents:(NSArray*)agents maxDistance:(float)maxDistance maxAngle:(float)maxAngle {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToCohereWithAgents:(NSArray*)agents maxDistance:(float)maxDistance maxAngle:(float)maxAngle {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToStayOnPath:(GKPath*)path maxPredictionTime:(NSTimeInterval)maxPredictionTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)goalToFollowPath:(GKPath*)path maxPredictionTime:(NSTimeInterval)maxPredictionTime forward:(BOOL)forward {
    UNIMPLEMENTED();
    return StubReturn();
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
