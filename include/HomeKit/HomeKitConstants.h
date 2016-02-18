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

#import <HomeKit/HomeKitExport.h>
#import <Foundation/NSObjCRuntime.h>

@class NSString;

typedef NS_ENUM(NSInteger, HMErrorCode) {
    HMErrorCodeAlreadyExists = 1,
    HMErrorCodeNotFound = 2,
    HMErrorCodeInvalidParameter = 3,
    HMErrorCodeAccessoryNotReachable = 4,
    HMErrorCodeReadOnlyCharacteristic = 5,
    HMErrorCodeWriteOnlyCharacteristic = 6,
    HMErrorCodeNotificationNotSupported = 7,
    HMErrorCodeOperationTimedOut = 8,
    HMErrorCodeAccessoryPoweredOff = 9,
    HMErrorCodeAccessDenied = 10,
    HMErrorCodeObjectAssociatedToAnotherHome = 11,
    HMErrorCodeObjectNotAssociatedToAnyHome = 12,
    HMErrorCodeObjectAlreadyAssociatedToHome = 13,
    HMErrorCodeAccessoryIsBusy = 14,
    HMErrorCodeOperationInProgress = 15,
    HMErrorCodeAccessoryOutOfResources = 16,
    HMErrorCodeInsufficientPrivileges = 17,
    HMErrorCodeAccessoryPairingFailed = 18,
    HMErrorCodeInvalidDataFormatSpecified = 19,
    HMErrorCodeNilParameter = 20,
    HMErrorCodeUnconfiguredParameter = 21,
    HMErrorCodeInvalidClass = 22,
    HMErrorCodeOperationCancelled = 23,
    HMErrorCodeRoomForHomeCannotBeInZone = 24,
    HMErrorCodeNoActionsInActionSet = 25,
    HMErrorCodeNoRegisteredActionSets = 26,
    HMErrorCodeMissingParameter = 27,
    HMErrorCodeFireDateInPast = 28,
    HMErrorCodeRoomForHomeCannotBeUpdated = 29,
    HMErrorCodeActionInAnotherActionSet = 30,
    HMErrorCodeObjectWithSimularNameExistsInHome = 31,
    HMErrorCodeHomeWithSimularNameExists = 32,
    HMErrorCodeRenameWithSimilarName = 33,
    HMErrorCodeCannotRemoveNonBridgeAccessory = 34,
    HMErrorCodeNameContainsProhibitedCharacters = 34,
    HMErrorCodeNameDoesNotStartWithValidCharacters = 36,
    HMErrorCodeUserIDNotEmailAddress = 37,
    HMErrorCodeUserDeclinedAddingUser = 38,
    HMErrorCodeUserDeclinedRemovingUser = 39,
    HMErrorCodeUserDeclinedInvite = 40,
    HMErrorCodeUserManagementFailed = 41,
    HMErrorCodeRecurrenceTooSmall = 42,
    HMErrorCodeInvalidValueType = 43,
    HMErrorCodeValueLowerThanMinimum = 44,
    HMErrorCodeValueHigherThanMaximum = 45,
    HMErrorCodeStringLongerThanMaximum = 46,
    HMErrorCodeHomeAccessNotAuthorized = 47,
    HMErrorCodeOperationNotSupported = 48,
    HMErrorCodeMaximumObjectLimitReached = 49,
    HMErrorCodeAccessorySentInvalidResponse = 50,
    HMErrorCodeStringShorterThanMinimum = 51,
    HMErrorCodeGenericError = 52,
    HMErrorCodeSecurityFailure = 53,
    HMErrorCodeCommunicationFailure = 54,
    HMErrorCodeMessageAuthenticationFailed = 55,
    HMErrorCodeInvalidMessageSize = 56,
    HMErrorCodeAccessoryDiscoveryFailed = 57,
    HMErrorCodeClientRequestError = 58,
    HMErrorCodeAccessoryResponseError = 59,
    HMErrorCodeNameDoesNotEndWithValidCharacters = 60,
    HMErrorCodeAccessoryIsBlocked = 61,
    HMErrorCodeInvalidAssociatedServiceType = 62,
    HMErrorCodeActionSetExecutionFailed = 63,
    HMErrorCodeActionSetExecutionPartialSuccess = 64,
    HMErrorCodeActionSetExecutionInProgress = 65,
    HMErrorCodeAccessoryOutOfCompliance = 66,
    HMErrorCodeDataResetFailure = 67,
    HMErrorCodeNotificationAlreadyEnabled = 68,
    HMErrorCodeRecurrenceMustBeOnSpecifiedBoundaries = 69,
    HMErrorCodeDateMustBeOnSpecifiedBoundaries = 70,
    HMErrorCodeCannotActivateTriggerTooFarInFuture = 71,
    HMErrorCodeRecurrenceTooLarge = 72,
    HMErrorCodeReadWritePartialSuccess = 73,
    HMErrorCodeReadWriteFailure = 74,
    HMErrorCodeNotSignedIntoiCloud = 75,
    HMErrorCodeKeychainSyncNotEnabled = 76,
    HMErrorCodeCloudDataSyncInProgress = 77,
    HMErrorCodeNetworkUnavailable = 78,
    HMErrorCodeAddAccessoryFailed = 79,
    HMErrorCodeMissingEntitlement = 80,
};

HOMEKIT_EXPORT NSString* const HMErrorDomain;
