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

#import <GameKit/GameKitExport.h>

#import <Foundation/NSObject.h>
#import <Foundation/NSObjCRuntime.h>

#import <GameKit/GKChallenge.h>

@class NSString;
@class GKPlayer;
@class NSDate;
@class NSArray;
@class NSError;
@class UIViewController;

GAMEKIT_EXPORT_CLASS
@interface GKScore : NSObject <NSCoding, NSObject, NSSecureCoding>
- (instancetype)initWithLeaderboardIdentifier:(NSString*)initializer STUB_METHOD;
- (instancetype)initWithLeaderboardIdentifier:(NSString*)identifier player:(GKPlayer*)player STUB_METHOD;
+ (void)reportScores:(NSArray*)scores withCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
+ (void)reportScores:(NSArray*)scores
    withEligibleChallenges:(NSArray*)challenges
     withCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (UIViewController*)challengeComposeControllerWithMessage:(NSString*)message
                                                   players:(NSArray*)players
                                         completionHandler:(GKChallengeComposeCompletionBlock)completionHandler STUB_METHOD;
- (UIViewController*)challengeComposeControllerWithPlayers:(NSArray*)playerIDs
                                                   message:(NSString*)message
                                         completionHandler:(GKChallengeComposeCompletionBlock)completionHandler STUB_METHOD;
- (instancetype)initWithCategory:(NSString*)category STUB_METHOD;
- (instancetype)initWithLeaderboardIdentifier:(NSString*)identifier forPlayer:(NSString*)playerID STUB_METHOD;
- (void)issueChallengeToPlayers:(NSArray*)playerIDs message:(NSString*)message STUB_METHOD;
- (void)reportScoreWithCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
@property (assign, nonatomic) uint64_t context STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSDate* date STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* formattedValue STUB_PROPERTY;
@property (copy, nonatomic) NSString* leaderboardIdentifier STUB_PROPERTY;
@property (readonly, retain, nonatomic) GKPlayer* player STUB_PROPERTY;
@property (readonly, assign, nonatomic) NSInteger rank STUB_PROPERTY;
@property (assign, nonatomic) int64_t value STUB_PROPERTY;
@property (assign, nonatomic) BOOL shouldSetDefaultLeaderboard STUB_PROPERTY;
@property (copy, nonatomic) NSString* category STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* playerID STUB_PROPERTY;
@end
