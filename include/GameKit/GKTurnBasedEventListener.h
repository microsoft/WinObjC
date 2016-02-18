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

@class GKPlayer;
@class GKTurnBasedExchange;
@class GKTurnBasedMatch;
@class NSArray;

@protocol GKTurnBasedEventListener
@optional
- (void)player:(GKPlayer*)player receivedExchangeCancellation:(GKTurnBasedExchange*)exchange forMatch:(GKTurnBasedMatch*)match;
- (void)player:(GKPlayer*)player
    receivedExchangeReplies:(NSArray*)replies
       forCompletedExchange:(GKTurnBasedExchange*)exchange
                   forMatch:(GKTurnBasedMatch*)match;
- (void)player:(GKPlayer*)player receivedExchangeRequest:(GKTurnBasedExchange*)exchange forMatch:(GKTurnBasedMatch*)match;
- (void)player:(GKPlayer*)player didRequestMatchWithOtherPlayers:(NSArray*)playersToInvite;
- (void)player:(GKPlayer*)player didRequestMatchWithPlayers:(NSArray*)playerIDsToInvite;
- (void)player:(GKPlayer*)player matchEnded:(GKTurnBasedMatch*)match;
- (void)player:(GKPlayer*)player receivedTurnEventForMatch:(GKTurnBasedMatch*)match didBecomeActive:(BOOL)didBecomeActive;
- (void)player:(GKPlayer*)player wantsToQuitMatch:(GKTurnBasedMatch*)match;
@end
