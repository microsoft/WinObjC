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
#import <Foundation/NSRange.h>

@class NSArray;
@class NSError;
@class NSString;
@class UIImage;
@class GKScore;

typedef NSInteger GKLeaderboardTimeScope;
typedef NSInteger GKLeaderboardPlayerScope;

enum {
    GKLeaderboardTimeScopeToday = 0,
    GKLeaderboardTimeScopeWeek,
    GKLeaderboardTimeScopeAllTime,
};
enum {
    GKLeaderboardPlayerScopeGlobal = 0,
    GKLeaderboardPlayerScopeFriendsOnly,
};

GAMEKIT_EXPORT_CLASS
@interface GKLeaderboard : NSObject <NSObject>
+ (void)loadLeaderboardsWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
+ (void)loadCategoriesWithCompletionHandler:(void (^)(NSArray*, NSArray*, NSError*))completionHandler STUB_METHOD;
- (instancetype)init STUB_METHOD;
- (instancetype)initWithPlayerIDs:(NSArray*)playerIDs STUB_METHOD;
- (instancetype)initWithPlayers:(NSArray*)players STUB_METHOD;
- (void)loadImageWithCompletionHandler:(void (^)(UIImage*, NSError*))completionHandler STUB_METHOD;
- (void)loadScoresWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
+ (void)setDefaultLeaderboard:(NSString*)leaderboardIdentifier withCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
@property (readonly, retain, nonatomic) NSString* groupIdentifier STUB_PROPERTY;
@property (readonly, getter=isLoading) BOOL loading STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* title STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSArray* scores STUB_PROPERTY;
@property (readonly, retain, nonatomic) GKScore* localPlayerScore STUB_PROPERTY;
@property (readonly, assign, nonatomic) NSUInteger maxRange STUB_PROPERTY;
@property (assign, nonatomic) GKLeaderboardPlayerScope playerScope STUB_PROPERTY;
@property (assign, nonatomic) NSRange range STUB_PROPERTY;
@property (assign, nonatomic) GKLeaderboardTimeScope timeScope STUB_PROPERTY;
@property (copy, nonatomic) NSString* identifier STUB_PROPERTY;
@property (copy, nonatomic) NSString* category STUB_PROPERTY;
@end
