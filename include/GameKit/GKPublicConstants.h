//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _GKPUBLICONSTANTS_H_
#define _GKPUBLICONSTANTS_H_

#include <stdint.h>

enum {
    GKSendDataReliable,
    GKSendDataUnreliable,
};
typedef uint32_t GKSendDataMode;

NSString* const GKErrorDomain;

typedef NS_ENUM(NSInteger, GKErrorCode) {
    GKErrorUnknown = 1,
    GKErrorCancelled = 2,
    GKErrorCommunicationsFailure = 3,
    GKErrorUserDenied = 4,
    GKErrorInvalidCredentials = 5,
    GKErrorNotAuthenticated = 6,
    GKErrorAuthenticationInProgress = 7,
    GKErrorInvalidPlayer = 8,
    GKErrorScoreNotSet = 9,
    GKErrorParentalControlsBlocked = 10,
    GKErrorPlayerStatusExceedsMaximumLength = 11,
    GKErrorPlayerStatusInvalid = 12,
    GKErrorMatchRequestInvalid = 13,
    GKErrorUnderage = 14,
    GKErrorGameUnrecognized = 15,
    GKErrorNotSupported = 16,
    GKErrorInvalidParameter = 17,
    GKErrorUnexpectedConnection = 18,
    GKErrorChallengeInvalid = 19,
    GKErrorTurnBasedMatchDataTooLarge = 20,
    GKErrorTurnBasedTooManySessions = 21,
    GKErrorTurnBasedInvalidParticipant = 22,
    GKErrorTurnBasedInvalidTurn = 23,
    GKErrorTurnBasedInvalidState = 24,
    GKErrorInvitationsDisabled = 25,
    GKErrorPlayerPhotoFailure = 26,
    GKErrorUbiquityContainerUnavailable = 27
};

#endif // _GKPUBLICONSTANTS_H_