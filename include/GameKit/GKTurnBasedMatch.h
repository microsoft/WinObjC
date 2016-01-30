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

@class NSArray;
@class NSError;
@class NSString;
@class GKMatchRequest;
@class NSDate;
@class GKTurnBasedParticipant;
@class NSData;
@class GKTurnBasedExchange;

typedef NSInteger GKTurnBasedMatchStatus;
typedef NSInteger GKTurnBasedMatchOutcome;

enum {
    GKTurnBasedMatchStatusUnknown = 0,
    GKTurnBasedMatchStatusOpen = 1,
    GKTurnBasedMatchStatusEnded = 2,
    GKTurnBasedMatchStatusMatching = 3,
};

GAMEKIT_EXPORT const NSTimeInterval GKTurnTimeoutDefault;
GAMEKIT_EXPORT const NSTimeInterval GKTurnTimeoutNone;

GAMEKIT_EXPORT_CLASS
@interface GKTurnBasedMatch : NSObject <NSObject>
+ (void)loadMatchesWithCompletionHandler:(void (^)(NSArray*, NSError*))completionHandler STUB_METHOD;
+ (void)loadMatchWithID:(NSString*)matchID withCompletionHandler:(void (^)(GKTurnBasedMatch*, NSError*))completionHandler STUB_METHOD;
+ (void)findMatchForRequest:(GKMatchRequest*)request
      withCompletionHandler:(void (^)(GKTurnBasedMatch*, NSError*))completionHandler STUB_METHOD;
- (void)acceptInviteWithCompletionHandler:(void (^)(GKTurnBasedMatch*, NSError*))completionHandler STUB_METHOD;
- (void)declineInviteWithCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)rematchWithCompletionHandler:(void (^)(GKTurnBasedMatch*, NSError*))completionHandler STUB_METHOD;
- (void)loadMatchDataWithCompletionHandler:(void (^)(NSData*, NSError*))completionHandler STUB_METHOD;
- (void)saveCurrentTurnWithMatchData:(NSData*)matchData completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)endTurnWithNextParticipants:(NSArray*)nextParticipants
                        turnTimeout:(NSTimeInterval)timeout
                          matchData:(NSData*)matchData
                  completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)endTurnWithNextParticipant:(GKTurnBasedParticipant*)nextParticipant
                         matchData:(NSData*)matchData
                 completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)participantQuitInTurnWithOutcome:(GKTurnBasedMatchOutcome)matchOutcome
                        nextParticipants:(NSArray*)nextParticipants
                             turnTimeout:(NSTimeInterval)timeout
                               matchData:(NSData*)matchData
                       completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)participantQuitInTurnWithOutcome:(GKTurnBasedMatchOutcome)matchOutcome
                         nextParticipant:(GKTurnBasedParticipant*)nextParticipant
                               matchData:(NSData*)matchData
                       completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)participantQuitOutOfTurnWithOutcome:(GKTurnBasedMatchOutcome)matchOutcome
                      withCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)endMatchInTurnWithMatchData:(NSData*)matchData
                             scores:(NSArray*)scores
                       achievements:(NSArray*)achievements
                  completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)endMatchInTurnWithMatchData:(NSData*)matchData completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)removeWithCompletionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)saveMergedMatchData:(NSData*)matchData
      withResolvedExchanges:(NSArray*)exchanges
          completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)sendExchangeToParticipants:(NSArray*)participants
                              data:(NSData*)data
             localizableMessageKey:(NSString*)key
                         arguments:(NSArray*)arguments
                           timeout:(NSTimeInterval)timeout
                 completionHandler:(void (^)(GKTurnBasedExchange*, NSError*))completionHandler STUB_METHOD;
- (void)sendReminderToParticipants:(NSArray*)participants
             localizableMessageKey:(NSString*)key
                         arguments:(NSArray*)arguments
                 completionHandler:(void (^)(NSError*))completionHandler STUB_METHOD;
- (void)setLocalizableMessageWithKey:(NSString*)key arguments:(NSArray*)arguments STUB_METHOD;
@property (readonly, retain, nonatomic) NSArray* activeExchanges STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSArray* completedExchanges STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger exchangeDataMaximumSize STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger exchangeMaxInitiatedExchangesPerPlayer STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSArray* exchanges STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSDate* creationDate STUB_PROPERTY;
@property (readonly, retain, nonatomic) GKTurnBasedParticipant* currentParticipant STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* matchID STUB_PROPERTY;
@property (readwrite, copy, nonatomic) NSString* message STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSArray* participants STUB_PROPERTY;
@property (readonly, nonatomic) GKTurnBasedMatchStatus status STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger matchDataMaximumSize STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSData* matchData STUB_PROPERTY;
@end
