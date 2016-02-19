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
#import <GameKit/GKAchievement.h>

@implementation GKAchievement
/**
 @Status Stub
 @Notes
*/
+ (void)loadAchievementsWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithIdentifier:(NSString*)identifier player:(GKPlayer*)player {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (void)reportAchievements:(NSArray*)achievements withCompletionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)reportAchievements:(NSArray*)achievements
    withEligibleChallenges:(NSArray*)challenges
     withCompletionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)resetAchievementsWithCompletionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (UIViewController*)challengeComposeControllerWithMessage:(NSString*)message
                                                   players:(NSArray*)players
                                         completionHandler:(GKChallengeComposeCompletionBlock)completionHandler {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)selectChallengeablePlayers:(NSArray*)players withCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (UIViewController*)challengeComposeControllerWithPlayers:(NSArray*)playerIDs
                                                   message:(NSString*)message
                                         completionHandler:(GKChallengeComposeCompletionBlock)completionHandler {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithIdentifier:(NSString*)identifier forPlayer:(NSString*)player_ID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)issueChallengeToPlayers:(NSArray*)playerIDs message:(NSString*)message {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)reportAchievementWithCompletionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)selectChallengeablePlayerIDs:(NSArray*)playerIDs withCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
