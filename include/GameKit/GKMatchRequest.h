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
@class GKPlayer;

typedef NSUInteger GKMatchType;
typedef NSInteger GKInviteRecipientResponse;
typedef NSInteger GKInviteeResponse;

enum {
    GKMatchTypePeerToPeer,
    GKMatchTypeHosted,
    GKMatchTypeTurnBased,
};
enum {
    GKInviteRecipientResponseAccepted = 0,
    GKInviteRecipientResponseDeclined = 1,
    GKInviteRecipientResponseFailed = 2,
    GKInviteRecipientResponseIncompatible = 3,
    GKInviteRecipientResponseUnableToConnect = 4,
    GKInviteRecipientResponseNoAnswer = 5,
};

enum {
    GKInviteeResponseAccepted = 0,
    GKInviteeResponseDeclined = 1,
    GKInviteeResponseFailed = 2,
    GKInviteeResponseIncompatible = 3,
    GKInviteeResponseUnableToConnect = 4,
    GKInviteeResponseNoAnswer = 5,
};

GAMEKIT_EXPORT_CLASS
@interface GKMatchRequest : NSObject <NSObject>
+ (NSUInteger)maxPlayersAllowedForMatchOfType:(GKMatchType)matchType STUB_METHOD;
@property (assign) NSUInteger maxPlayers STUB_PROPERTY;
@property (assign) NSUInteger minPlayers STUB_PROPERTY;
@property (assign) NSUInteger defaultNumberOfPlayers STUB_PROPERTY;
@property (copy) NSString* inviteMessage STUB_PROPERTY;
@property (assign) NSUInteger playerGroup STUB_PROPERTY;
@property (assign) uint32_t playerAttributes STUB_PROPERTY;
@property (retain) NSArray* playersToInvite STUB_PROPERTY;
@property (retain) NSArray* recipients STUB_PROPERTY;
@property (copy, nonnull) void (^recipientResponseHandler)(GKPlayer*, GKInviteRecipientResponse) STUB_PROPERTY;
@property (copy, nonnull) void (^inviteeResponseHandler)(NSString*, GKInviteeResponse) STUB_PROPERTY;
@end
