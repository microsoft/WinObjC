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

@class NSDate;
@class GKPlayer;
@class NSString;

typedef NSInteger GKTurnBasedMatchOutcome;
typedef NSInteger GKTurnBasedParticipantStatus;

enum {
    GKTurnBasedMatchOutcomeNone = 0,
    GKTurnBasedMatchOutcomeQuit = 1,
    GKTurnBasedMatchOutcomeWon = 2,
    GKTurnBasedMatchOutcomeLost = 3,
    GKTurnBasedMatchOutcomeTied = 4,
    GKTurnBasedMatchOutcomeTimeExpired = 5,
    GKTurnBasedMatchOutcomeFirst = 6,
    GKTurnBasedMatchOutcomeSecond = 7,
    GKTurnBasedMatchOutcomeThird = 8,
    GKTurnBasedMatchOutcomeFourth = 9,
    GKTurnBasedMatchOutcomeCustomRange = 0x00FF0000,
};

enum {
    GKTurnBasedParticipantStatusUnknown = 0,
    GKTurnBasedParticipantStatusInvited = 1,
    GKTurnBasedParticipantStatusDeclined = 2,
    GKTurnBasedParticipantStatusMatching = 3,
    GKTurnBasedParticipantStatusActive = 4,
    GKTurnBasedParticipantStatusDone = 5,
};

GAMEKIT_EXPORT_CLASS
@interface GKTurnBasedParticipant : NSObject <NSObject>
@property (readonly, copy, nonatomic) NSDate* lastTurnDate STUB_PROPERTY;
@property (readonly, retain, nonatomic) GKPlayer* player STUB_PROPERTY;
@property (readonly, nonatomic) GKTurnBasedParticipantStatus status STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSDate* timeoutDate STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* playerID STUB_PROPERTY;
@property (assign, nonatomic) GKTurnBasedMatchOutcome matchOutcome STUB_PROPERTY;
@end
