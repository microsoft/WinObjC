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

#import <Foundation/NSObjCRuntime.h>
#import <Foundation/NSObject.h>

@class GKInvite;
@class GKMatch;
@class NSError;
@class NSArray;
@class GKMatchRequest;
@class GKPlayer;
@class NSString;

GAMEKIT_EXPORT_CLASS
@interface GKMatchmaker : NSObject <NSObject>
+ (GKMatchmaker*)sharedMatchmaker STUB_METHOD;
- (void)matchForInvite:(GKInvite*)invite completionHandler:(void (^)(GKMatch*, NSError*))completionHandler STUB_METHOD;
- (void)addPlayersToMatch:(GKMatch*)match
             matchRequest:(GKMatchRequest*)matchRequest
        completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)cancel STUB_METHOD;
- (void)cancelPendingInviteToPlayer:(GKPlayer*)player STUB_METHOD;
- (void)findMatchForRequest:(GKMatchRequest*)request withCompletionHandler:(void (^)(GKMatch*, NSError*))completionHandler STUB_METHOD;
- (void)findPlayersForHostedRequest:(GKMatchRequest*)request
              withCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)finishMatchmakingForMatch:(GKMatch*)match STUB_METHOD;
- (void)queryActivityWithCompletionHandler:(void (^)(NSInteger, NSError*))completionHandler STUB_METHOD;
- (void)queryPlayerGroupActivity:(NSUInteger)playerGroup withCompletionHandler:(void (^)(NSInteger, NSError*))completionHandler STUB_METHOD;
- (void)cancelInviteToPlayer:(NSString*)playerID STUB_METHOD;
- (void)findPlayersForHostedMatchRequest:(GKMatchRequest*)request
                   withCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
- (void)startBrowsingForNearbyPlayersWithHandler:(void (^)(GKPlayer*, BOOL))reachableHandler STUB_METHOD;
- (void)stopBrowsingForNearbyPlayers STUB_METHOD;
- (void)startBrowsingForNearbyPlayersWithReachableHandler:(void (^)(NSString*, BOOL))reachableHandler STUB_METHOD;
@property (copy, nonatomic, nonnull) void (^inviteHandler)(GKInvite*, NSArray*) STUB_PROPERTY;
@end
