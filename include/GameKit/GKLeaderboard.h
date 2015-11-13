//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _GKLEADERBOARD_H_
#define _GKLEADERBOARD_H_

#import <GameKit/GameKitExport.h>
#import <Foundation/NSRange.h>
#include <GameKit/GKScore.h>
#include <stdint.h>

enum {
    GKLeaderboardPlayerScopeGlobal = 0,
    GKLeaderboardPlayerScopeFriendsOnly = 1,
};
typedef uint32_t GKLeaderboardPlayerScope;

enum {
    GKLeaderboardTimeScopeToday = 0,
    GKLeaderboardTimeScopeWeek = 1,
    GKLeaderboardTimeScopeAllTime = 2,
};
typedef uint32_t GKLeaderboardTimeScope;

@class NSArray;
@class NSError;

@interface GKLeaderboard : NSObject

@property (nonatomic, retain) NSString* category;
@property (nonatomic, assign) GKLeaderboardPlayerScope playerScope;
@property (nonatomic, assign) GKLeaderboardTimeScope timeScope;
@property (nonatomic, assign) NSRange range;
@property (nonatomic, readonly, retain) NSArray* scores;
@property (nonatomic, readonly, retain) GKScore* localPlayerScore;
@property (readonly, getter=isLoading) BOOL loading;

+ (void)loadCategoriesWithCompletionHandler:(void (^)(NSArray* categories, NSArray* titles, NSError* error))completionHandler;

- (id)initWithPlayerIDs:(NSArray*)playerIDs;
- (void)loadScoresWithCompletionHandler:(void (^)(NSArray* scores, NSError* error))completionHandler;

@end

#endif /* _GKLEADERBOARD_H_ */