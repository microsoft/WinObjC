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
#import <GamePlayKit/GKRandom.h>

#import <Foundation/NSObject.h>

GAMEPLAYKIT_EXPORT_CLASS
@interface GKRandomDistribution : NSObject <GKRandom>
- (instancetype)initWithRandomSource:(id<GKRandom>)source
                         lowestValue:(NSInteger)lowestInclusive
                        highestValue:(NSInteger)highestInclusive STUB_METHOD;
+ (instancetype)distributionWithLowestValue:(NSInteger)lowestInclusive highestValue:(NSInteger)highestInclusive STUB_METHOD;
+ (instancetype)d6 STUB_METHOD;
+ (instancetype)d20 STUB_METHOD;
+ (instancetype)distributionForDieWithSideCount:(NSInteger)sideCount STUB_METHOD;
- (NSInteger)nextInt STUB_METHOD;
- (NSUInteger)nextIntWithUpperBound:(NSUInteger)upperBound STUB_METHOD;
- (float)nextUniform STUB_METHOD;
- (BOOL)nextBool STUB_METHOD;
@property (readonly, assign, nonatomic) NSInteger lowestValue STUB_PROPERTY;
@property (readonly, assign, nonatomic) NSInteger highestValue STUB_PROPERTY;
@property (readonly, assign, nonatomic) NSUInteger numberOfPossibleOutcomes STUB_PROPERTY;
@end
