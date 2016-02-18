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

#import <CloudKit/CloudKitExport.h>
#import <Foundation/NSObjCRuntime.h>

@class NSString;

typedef enum : NSInteger {
    CKErrorInternalError = 1,
    CKErrorPartialFailure = 2,
    CKErrorNetworkUnavailable = 3,
    CKErrorNetworkFailure = 4,
    CKErrorBadContainer = 5,
    CKErrorServiceUnavailable = 6,
    CKErrorRequestRateLimited = 7,
    CKErrorMissingEntitlement = 8,
    CKErrorNotAuthenticated = 9,
    CKErrorPermissionFailure = 10,
    CKErrorUnknownItem = 11,
    CKErrorInvalidArguments = 12,
    CKErrorResultsTruncated = 13,
    CKErrorServerRecordChanged = 14,
    CKErrorServerRejectedRequest = 15,
    CKErrorAssetFileNotFound = 16,
    CKErrorAssetFileModified = 17,
    CKErrorIncompatibleVersion = 18,
    CKErrorConstraintViolation = 19,
    CKErrorOperationCancelled = 20,
    CKErrorChangeTokenExpired = 21,
    CKErrorBatchRequestFailed = 22,
    CKErrorZoneBusy = 23,
    CKErrorBadDatabase = 24,
    CKErrorQuotaExceeded = 25,
    CKErrorZoneNotFound = 26,
    CKErrorLimitExceeded = 27,
    CKErrorUserDeletedZone = 28,
} CKErrorCode;

CLOUDKIT_EXPORT NSString* const CKErrorDomain;
CLOUDKIT_EXPORT NSString* const CKPartialErrorsByItemIDKey;
CLOUDKIT_EXPORT NSString* const CKRecordChangedErrorAncestorRecordKey;
CLOUDKIT_EXPORT NSString* const CKRecordChangedErrorServerRecordKey;
CLOUDKIT_EXPORT NSString* const CKRecordChangedErrorClientRecordKey;
CLOUDKIT_EXPORT NSString* const CKErrorRetryAfterKey;