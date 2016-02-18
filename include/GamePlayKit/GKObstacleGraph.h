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
#import <GamePlayKit/GKGraph.h>

#import <Foundation/NSObject.h>

@class NSArray;
@class GKPolygonObstacle;
@class GKGraphNode2D;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKObstacleGraph : GKGraph
- (instancetype)initWithObstacles:(NSArray*)obstacles bufferRadius:(float)bufferRadius STUB_METHOD;
+ (instancetype)graphWithObstacles:(NSArray*)obstacles bufferRadius:(float)bufferRadius STUB_METHOD;
@property (readonly, nonatomic) NSArray* obstacles STUB_PROPERTY;
- (void)addObstacles:(NSArray*)obstacles STUB_METHOD;
- (void)removeObstacles:(NSArray*)obstacles STUB_METHOD;
- (void)removeAllObstacles STUB_METHOD;
- (NSArray*)nodesForObstacle:(GKPolygonObstacle*)obstacle STUB_METHOD;
- (void)connectNodeUsingObstacles:(GKGraphNode2D*)node STUB_METHOD;
- (void)connectNodeUsingObstacles:(GKGraphNode2D*)node ignoringObstacles:(NSArray*)obstaclesToIgnore STUB_METHOD;
- (void)connectNodeUsingObstacles:(GKGraphNode2D*)node ignoringBufferRadiusOfObstacles:(NSArray*)obstaclesBufferRadiusToIgnore STUB_METHOD;
@property (readonly, nonatomic) float bufferRadius STUB_PROPERTY;
- (void)lockConnectionFromNode:(GKGraphNode2D*)startNode toNode:(GKGraphNode2D*)endNode STUB_METHOD;
- (void)unlockConnectionFromNode:(GKGraphNode2D*)startNode toNode:(GKGraphNode2D*)endNode STUB_METHOD;
- (BOOL)isConnectionLockedFromNode:(GKGraphNode2D*)startNode toNode:(GKGraphNode2D*)endNode STUB_METHOD;
@end
