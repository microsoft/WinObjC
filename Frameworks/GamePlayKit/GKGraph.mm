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

#import <GamePlayKit/GKGraph.h>

@implementation GKGraph
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithNodes:(NSArray*)nodes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)graphWithNodes:(NSArray*)nodes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addNodes:(NSArray*)nodes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)connectNodeToLowestCostNode:(GKGraphNode*)node bidirectional:(BOOL)bidirectional {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeNodes:(NSArray*)nodes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)findPathFromNode:(GKGraphNode*)startNode toNode:(GKGraphNode*)endNode {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
