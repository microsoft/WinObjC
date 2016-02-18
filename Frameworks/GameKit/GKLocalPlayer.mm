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
#import <GameKit/GKLocalPlayer.h>

@implementation GKLocalPlayer
/**
 @Status Stub
 @Notes
*/
+ (GKLocalPlayer*)localPlayer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)generateIdentityVerificationSignatureWithCompletionHandler:
    (void (^)(NSURL*, NSData*, NSData*, uint64_t, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)loadFriendPlayersWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)loadDefaultLeaderboardIdentifierWithCompletionHandler:(void (^)(NSString*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setDefaultLeaderboardIdentifier:(NSString*)leaderboardIdentifier completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)registerListener:(id<GKLocalPlayerListener>)listener {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)unregisterAllListeners {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)unregisterListener:(id<GKLocalPlayerListener>)listener {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)deleteSavedGamesWithName:(NSString*)name completionHandler:(void (^)(NSError*))handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)fetchSavedGamesWithCompletionHandler:(void (^)(NSArray*, NSError*))handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)resolveConflictingSavedGames:(NSArray*)conflictingSavedGames
                            withData:(NSData*)data
                   completionHandler:(void (^)(NSArray*, NSError*))handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)saveGameData:(NSData*)data withName:(NSString*)name completionHandler:(void (^)(GKSavedGame*, NSError*))handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)authenticateWithCompletionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)loadDefaultLeaderboardCategoryIDWithCompletionHandler:(void (^)(NSString*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)loadFriendsWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setDefaultLeaderboardCategoryID:(NSString*)categoryID completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

@end
