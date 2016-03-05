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
#import <GameKit/GKPlayer.h>

#import <Foundation/NSObject.h>

@class UIViewController;
@class NSError;
@class NSURL;
@class NSData;
@class NSArray;
@class NSString;
@protocol GKLocalPlayerListener;
@class GKSavedGame;

GAMEKIT_EXPORT_CLASS
@interface GKLocalPlayer : GKPlayer <NSObject>
+ (GKLocalPlayer*)localPlayer STUB_METHOD;
- (void)generateIdentityVerificationSignatureWithCompletionHandler:(void (^)(NSURL*, NSData*, NSData*, uint64_t, NSError*))completionHandler
    STUB_METHOD;
- (void)loadFriendPlayersWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)loadDefaultLeaderboardIdentifierWithCompletionHandler:(void (^)(NSString*, NSError*))completionHandler STUB_METHOD;
- (void)setDefaultLeaderboardIdentifier:(NSString*)leaderboardIdentifier
                      completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)registerListener:(id<GKLocalPlayerListener>)listener STUB_METHOD;
- (void)unregisterAllListeners STUB_METHOD;
- (void)unregisterListener:(id<GKLocalPlayerListener>)listener STUB_METHOD;
- (void)deleteSavedGamesWithName:(NSString*)name completionHandler:(void (^)(NSError*))handler STUB_METHOD;
- (void)fetchSavedGamesWithCompletionHandler:(void (^)(NSArray*, NSError*))handler STUB_METHOD;
- (void)resolveConflictingSavedGames:(NSArray*)conflictingSavedGames
                            withData:(NSData*)data
                   completionHandler:(void (^)(NSArray*, NSError*))handler STUB_METHOD;
- (void)saveGameData:(NSData*)data withName:(NSString*)name completionHandler:(void (^)(GKSavedGame*, NSError*))handler STUB_METHOD;
- (void)authenticateWithCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)loadDefaultLeaderboardCategoryIDWithCompletionHandler:(void (^)(NSString*, NSError*))completionHandler STUB_METHOD;
- (void)loadFriendsWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)setDefaultLeaderboardCategoryID:(NSString*)categoryID completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
@property (copy, nonatomic, nullable) void (^authenticateHandler)(UIViewController*, NSError*) STUB_PROPERTY;
@property (readonly, getter=isAuthenticated, nonatomic) BOOL authenticated STUB_PROPERTY;
@property (readonly, getter=isUnderage, nonatomic) BOOL underage STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSArray* friends STUB_PROPERTY;
@end
