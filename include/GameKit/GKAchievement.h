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

#import <Foundation/NSObject.h>

#import <GameKit/GameKitExport.h>
#import <GameKit/GKChallenge.h>

@class NSArray;
@class NSError;
@class NSString;
@class GKPlayer;
@class NSDate;
@class UIViewController;

GAMEKIT_EXPORT_CLASS
@interface GKAchievement : NSObject <NSCoding, NSObject, NSSecureCoding>
+ (void)loadAchievementsWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (instancetype)initWithIdentifier:(NSString*)identifier STUB_METHOD;
- (instancetype)initWithIdentifier:(NSString*)identifier player:(GKPlayer*)player STUB_METHOD;
+ (void)reportAchievements:(NSArray*)achievements withCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
+ (void)reportAchievements:(NSArray*)achievements
    withEligibleChallenges:(NSArray*)challenges
     withCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;

+ (void)resetAchievementsWithCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (UIViewController*)challengeComposeControllerWithMessage:(NSString*)message
                                                   players:(NSArray*)players
                                         completionHandler:(GKChallengeComposeCompletionBlock)completionHandler STUB_METHOD;
- (void)selectChallengeablePlayers:(NSArray*)players withCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;

- (UIViewController*)challengeComposeControllerWithPlayers:(NSArray*)playerIDs
                                                   message:(NSString*)message
                                         completionHandler:(GKChallengeComposeCompletionBlock)completionHandler STUB_METHOD;

- (instancetype)initWithIdentifier:(NSString*)identifier forPlayer:(NSString*)player_ID STUB_METHOD;
- (void)issueChallengeToPlayers:(NSArray*)playerIDs message:(NSString*)message STUB_METHOD;
- (void)reportAchievementWithCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)selectChallengeablePlayerIDs:(NSArray*)playerIDs withCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
@property (readonly, copy, nonatomic) NSString* playerID STUB_PROPERTY;
@property (readonly, getter=isHidden, assign, nonatomic) BOOL hidden STUB_PROPERTY;
@property (readonly, retain, nonatomic) GKPlayer* player STUB_PROPERTY;
@property (assign, nonatomic) BOOL showsCompletionBanner STUB_PROPERTY;
@property (copy, nonatomic) NSString* identifier STUB_PROPERTY;
@property (assign, nonatomic) double percentComplete STUB_PROPERTY;
@property (readonly, getter=isCompleted, nonatomic) BOOL completed STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSDate* lastReportedDate STUB_PROPERTY;
@end
