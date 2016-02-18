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

#import <Contacts/ContactsExport.h>
#import <Foundation/NSObject.h>

@class NSString;

typedef NS_ENUM(NSInteger, CNErrorCode) {
    CNErrorCodeCommunicationError = 1,
    CNErrorCodeDataAccessError = 2,
    CNErrorCodeAuthorizationDenied = 100,
    CNErrorCodeRecordDoesNotExist = 200,
    CNErrorCodeInsertedRecordAlreadyExists = 201,
    CNErrorCodeContainmentCycle = 202,
    CNErrorCodeContainmentScope = 203,
    CNErrorCodeParentRecordDoesNotExist = 204,
    CNErrorCodeValidationMultipleErrors = 300,
    CNErrorCodeValidationTypeMismatch = 301,
    CNErrorCodeValidationConfigurationError = 302,
    CNErrorCodePredicateInvalid = 400,
    CNErrorCodePolicyViolation = 500
};

CONTACTS_EXPORT NSString* const CNErrorUserInfoAffectedRecordsKey;
CONTACTS_EXPORT NSString* const CNErrorUserInfoAffectedRecordIdentifiersKey;
CONTACTS_EXPORT NSString* const CNErrorUserInfoValidationErrorsKey;
CONTACTS_EXPORT NSString* const CNErrorUserInfoKeyPathsKey;
