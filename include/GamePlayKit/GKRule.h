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

@class NSPredicate;
@class GKRuleSystem;

GAMEPLAYKIT_EXPORT_CLASS
@interface GKRule : NSObject
+ (instancetype)ruleWithPredicate:(NSPredicate*)pred assertingFact:(id<NSObject>)fact grade:(float)grade STUB_METHOD;
+ (instancetype)ruleWithPredicate:(NSPredicate*)pred retractingFact:(id<NSObject>)fact grade:(float)grade STUB_METHOD;
+ (instancetype)ruleWithBlockPredicate:(BOOL (^)(GKRuleSystem*))pred action:(void (^)(GKRuleSystem*))action STUB_METHOD;
@property (assign, nonatomic) NSInteger salience STUB_PROPERTY;
- (BOOL)evaluatePredicateWithSystem:(GKRuleSystem*)sys STUB_METHOD;
- (void)performActionWithSystem:(GKRuleSystem*)sys STUB_METHOD;
@end
