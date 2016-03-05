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

#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>

@class GKGoal;
@class NSArray;
@class NSDictionary;
@class NSNumber;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKBehavior : NSObject <NSFastEnumeration>
+ (instancetype)behaviorWithGoal:(GKGoal*)goal weight:(float)weight STUB_METHOD;
+ (instancetype)behaviorWithGoals:(NSArray*)goals STUB_METHOD;
+ (instancetype)behaviorWithGoals:(NSArray*)goals andWeights:(NSArray*)weights STUB_METHOD;
+ (instancetype)behaviorWithWeightedGoals:(NSDictionary*)weightedGoals STUB_METHOD;
- (void)setWeight:(float)weight forGoal:(GKGoal*)goal STUB_METHOD;
- (float)weightForGoal:(GKGoal*)goal STUB_METHOD;
- (void)removeGoal:(GKGoal*)goal STUB_METHOD;
- (void)removeAllGoals STUB_METHOD;
@property (readonly) NSInteger goalCount STUB_PROPERTY;
- (NSNumber*)objectForKeyedSubscript:(GKGoal*)goal STUB_METHOD;
- (void)setObject:(NSNumber*)weight forKeyedSubscript:(GKGoal*)goal STUB_METHOD;
- (GKGoal*)objectAtIndexedSubscript:(NSUInteger)idx STUB_METHOD;
@end
