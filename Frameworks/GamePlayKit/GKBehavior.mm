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

#import <GamePlayKit/GKBehavior.h>

@implementation GKBehavior
/**
 @Status Stub
 @Notes
*/
+ (instancetype)behaviorWithGoal:(GKGoal*)goal weight:(float)weight {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)behaviorWithGoals:(NSArray*)goals {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)behaviorWithGoals:(NSArray*)goals andWeights:(NSArray*)weights {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)behaviorWithWeightedGoals:(NSDictionary*)weightedGoals {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setWeight:(float)weight forGoal:(GKGoal*)goal {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (float)weightForGoal:(GKGoal*)goal {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeGoal:(GKGoal*)goal {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllGoals {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSNumber*)objectForKeyedSubscript:(GKGoal*)goal {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setObject:(NSNumber*)weight forKeyedSubscript:(GKGoal*)goal {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (GKGoal*)objectAtIndexedSubscript:(NSUInteger)idx {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id _Nonnull[])stackbuf count:(NSUInteger)len {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
