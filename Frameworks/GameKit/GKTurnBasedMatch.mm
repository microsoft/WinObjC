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
#import <GameKit/GKTurnBasedMatch.h>

/** @Status Stub */
const NSTimeInterval GKTurnTimeoutDefault = StubConstant();
/** @Status Stub */
const NSTimeInterval GKTurnTimeoutNone = StubConstant();

@implementation GKTurnBasedMatch
/**
 @Status Stub
 @Notes
*/
+ (void)loadMatchesWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)loadMatchWithID:(NSString*)matchID withCompletionHandler:(void (^)(GKTurnBasedMatch*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)findMatchForRequest:(GKMatchRequest*)request withCompletionHandler:(void (^)(GKTurnBasedMatch*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)acceptInviteWithCompletionHandler:(void (^)(GKTurnBasedMatch*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)declineInviteWithCompletionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)rematchWithCompletionHandler:(void (^)(GKTurnBasedMatch*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)loadMatchDataWithCompletionHandler:(void (^)(NSData*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)saveCurrentTurnWithMatchData:(NSData*)matchData completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)endTurnWithNextParticipants:(NSArray*)nextParticipants
                        turnTimeout:(NSTimeInterval)timeout
                          matchData:(NSData*)matchData
                  completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)endTurnWithNextParticipant:(GKTurnBasedParticipant*)nextParticipant
                         matchData:(NSData*)matchData
                 completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)participantQuitInTurnWithOutcome:(GKTurnBasedMatchOutcome)matchOutcome
                        nextParticipants:(NSArray*)nextParticipants
                             turnTimeout:(NSTimeInterval)timeout
                               matchData:(NSData*)matchData
                       completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)participantQuitInTurnWithOutcome:(GKTurnBasedMatchOutcome)matchOutcome
                         nextParticipant:(GKTurnBasedParticipant*)nextParticipant
                               matchData:(NSData*)matchData
                       completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)participantQuitOutOfTurnWithOutcome:(GKTurnBasedMatchOutcome)matchOutcome
                      withCompletionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)endMatchInTurnWithMatchData:(NSData*)matchData
                             scores:(NSArray*)scores
                       achievements:(NSArray*)achievements
                  completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)endMatchInTurnWithMatchData:(NSData*)matchData completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeWithCompletionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)saveMergedMatchData:(NSData*)matchData
      withResolvedExchanges:(NSArray*)exchanges
          completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)sendExchangeToParticipants:(NSArray*)participants
                              data:(NSData*)data
             localizableMessageKey:(NSString*)key
                         arguments:(NSArray*)arguments
                           timeout:(NSTimeInterval)timeout
                 completionHandler:(void (^)(GKTurnBasedExchange*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)sendReminderToParticipants:(NSArray*)participants
             localizableMessageKey:(NSString*)key
                         arguments:(NSArray*)arguments
                 completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setLocalizableMessageWithKey:(NSString*)key arguments:(NSArray*)arguments {
    UNIMPLEMENTED();
}

@end
