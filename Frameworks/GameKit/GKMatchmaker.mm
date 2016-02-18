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
#import <GameKit/GKMatchmaker.h>

@implementation GKMatchmaker
/**
 @Status Stub
 @Notes
*/
+ (GKMatchmaker*)sharedMatchmaker {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)matchForInvite:(GKInvite*)invite completionHandler:(void (^)(GKMatch*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addPlayersToMatch:(GKMatch*)match
             matchRequest:(GKMatchRequest*)matchRequest
        completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)cancel {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)cancelPendingInviteToPlayer:(GKPlayer*)player {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)findMatchForRequest:(GKMatchRequest*)request withCompletionHandler:(void (^)(GKMatch*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)findPlayersForHostedRequest:(GKMatchRequest*)request withCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)finishMatchmakingForMatch:(GKMatch*)match {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)queryActivityWithCompletionHandler:(void (^)(NSInteger, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)queryPlayerGroupActivity:(NSUInteger)playerGroup withCompletionHandler:(void (^)(NSInteger, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)cancelInviteToPlayer:(NSString*)playerID {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)findPlayersForHostedMatchRequest:(GKMatchRequest*)request withCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startBrowsingForNearbyPlayersWithHandler:(void (^)(GKPlayer*, BOOL))reachableHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopBrowsingForNearbyPlayers {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startBrowsingForNearbyPlayersWithReachableHandler:(void (^)(NSString*, BOOL))reachableHandler {
    UNIMPLEMENTED();
}

@end
