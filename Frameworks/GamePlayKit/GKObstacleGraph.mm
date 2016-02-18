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

#import <GamePlayKit/GKObstacleGraph.h>

@implementation GKObstacleGraph
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithObstacles:(NSArray*)obstacles bufferRadius:(float)bufferRadius {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)graphWithObstacles:(NSArray*)obstacles bufferRadius:(float)bufferRadius {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addObstacles:(NSArray*)obstacles {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObstacles:(NSArray*)obstacles {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllObstacles {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)nodesForObstacle:(GKPolygonObstacle*)obstacle {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)connectNodeUsingObstacles:(GKGraphNode2D*)node {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)connectNodeUsingObstacles:(GKGraphNode2D*)node ignoringObstacles:(NSArray*)obstaclesToIgnore {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)connectNodeUsingObstacles:(GKGraphNode2D*)node ignoringBufferRadiusOfObstacles:(NSArray*)obstaclesBufferRadiusToIgnore {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)lockConnectionFromNode:(GKGraphNode2D*)startNode toNode:(GKGraphNode2D*)endNode {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)unlockConnectionFromNode:(GKGraphNode2D*)startNode toNode:(GKGraphNode2D*)endNode {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isConnectionLockedFromNode:(GKGraphNode2D*)startNode toNode:(GKGraphNode2D*)endNode {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
