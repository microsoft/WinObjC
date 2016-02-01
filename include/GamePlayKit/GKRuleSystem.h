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

@class NSMutableDictionary;
@class NSArray;
@class GKRule;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKRuleSystem : NSObject
- (instancetype)init STUB_METHOD;
@property (readonly, retain, nonatomic) NSMutableDictionary* state STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSArray* rules STUB_PROPERTY;
- (void)addRule:(GKRule*)rule STUB_METHOD;
- (void)addRulesFromArray:(NSArray*)rules STUB_METHOD;
- (void)removeAllRules STUB_METHOD;
- (void)evaluate STUB_METHOD;
@property (readonly, retain, nonatomic) NSArray* agenda STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSArray* executed STUB_PROPERTY;
- (void)reset STUB_METHOD;
@property (readonly, retain, nonatomic) NSArray* facts STUB_PROPERTY;
- (void)assertFact:(id<NSObject>)fact STUB_METHOD;
- (void)assertFact:(id<NSObject>)fact grade:(float)grade STUB_METHOD;
- (void)retractFact:(id<NSObject>)fact STUB_METHOD;
- (void)retractFact:(id<NSObject>)fact grade:(float)grade STUB_METHOD;
- (float)gradeForFact:(id<NSObject>)fact STUB_METHOD;
- (float)minimumGradeForFacts:(NSArray*)facts STUB_METHOD;
- (float)maximumGradeForFacts:(NSArray*)facts STUB_METHOD;
@end
