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

#import <GamePlayKit/GameplayKitExport.h>

#import <Foundation/NSObject.h>

@class GKAgent;
@class NSArray;
@class GKPath;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKGoal : NSObject <NSCopying>
+ (instancetype)goalToSeekAgent:(GKAgent*)agent STUB_METHOD;
+ (instancetype)goalToFleeAgent:(GKAgent*)agent STUB_METHOD;
+ (instancetype)goalToReachTargetSpeed:(float)targetSpeed STUB_METHOD;
+ (instancetype)goalToWander:(float)speed STUB_METHOD;
+ (instancetype)goalToAvoidAgents:(NSArray*)agents maxPredictionTime:(NSTimeInterval)maxPredictionTime STUB_METHOD;
+ (instancetype)goalToAvoidObstacles:(NSArray*)obstacles maxPredictionTime:(NSTimeInterval)maxPredictionTime STUB_METHOD;
+ (instancetype)goalToInterceptAgent:(GKAgent*)target maxPredictionTime:(NSTimeInterval)maxPredictionTime STUB_METHOD;
+ (instancetype)goalToSeparateFromAgents:(NSArray*)agents maxDistance:(float)maxDistance maxAngle:(float)maxAngle STUB_METHOD;
+ (instancetype)goalToAlignWithAgents:(NSArray*)agents maxDistance:(float)maxDistance maxAngle:(float)maxAngle STUB_METHOD;
+ (instancetype)goalToCohereWithAgents:(NSArray*)agents maxDistance:(float)maxDistance maxAngle:(float)maxAngle STUB_METHOD;
+ (instancetype)goalToStayOnPath:(GKPath*)path maxPredictionTime:(NSTimeInterval)maxPredictionTime STUB_METHOD;
+ (instancetype)goalToFollowPath:(GKPath*)path maxPredictionTime:(NSTimeInterval)maxPredictionTime forward:(BOOL)forward STUB_METHOD;
@end
