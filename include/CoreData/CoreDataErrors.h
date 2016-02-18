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

#import <CoreData/CoreDataExport.h>

@class NSString;

COREDATA_EXPORT const NSString* NSDetailedErrorsKey;
COREDATA_EXPORT const NSString* NSValidationObjectErrorKey;
COREDATA_EXPORT const NSString* NSValidationKeyErrorKey;
COREDATA_EXPORT const NSString* NSValidationPredicateErrorKey;
COREDATA_EXPORT const NSString* NSValidationValueErrorKey;
COREDATA_EXPORT const NSString* NSAffectedStoresErrorKey;
COREDATA_EXPORT const NSString* NSAffectedObjectsErrorKey;
COREDATA_EXPORT const NSString* NSPersistentStoreSaveConflictsErrorKey;
COREDATA_EXPORT const NSString* NSSQLiteErrorDomain;

enum {
    NSManagedObjectValidationError = 1550,
    NSValidationMultipleErrorsError = 1560,
    NSValidationMissingMandatoryPropertyError = 1570,
    NSValidationRelationshipLacksMinimumCountError = 1580,
    NSValidationRelationshipExceedsMaximumCountError = 1590,
    NSValidationRelationshipDeniedDeleteError = 1600,
    NSValidationNumberTooLargeError = 1610,
    NSValidationNumberTooSmallError = 1620,
    NSValidationDateTooLateError = 1630,
    NSValidationDateTooSoonError = 1640,
    NSValidationInvalidDateError = 1650,
    NSValidationStringTooLongError = 1660,
    NSValidationStringTooShortError = 1670,
    NSValidationStringPatternMatchingError = 1680,
    NSManagedObjectContextLockingError = 132000,
    NSPersistentStoreCoordinatorLockingError = 132010,
    NSManagedObjectReferentialIntegrityError = 133000,
    NSManagedObjectExternalRelationshipError = 133010,
    NSManagedObjectMergeError = 133020,
    NSPersistentStoreInvalidTypeError = 134000,
    NSPersistentStoreTypeMismatchError = 134010,
    NSPersistentStoreIncompatibleSchemaError = 134020,
    NSPersistentStoreSaveError = 134030,
    NSPersistentStoreIncompleteSaveError = 134040,
    NSPersistentStoreSaveConflictsError = 134050,
    NSPersistentStoreOperationError = 134070,
    NSPersistentStoreOpenError = 134080,
    NSPersistentStoreTimeoutError = 134090,
    NSPersistentStoreIncompatibleVersionHashError = 134100,
    NSMigrationError = 134110,
    NSMigrationCancelledError = 134120,
    NSMigrationMissingSourceModelError = 134130,
    NSMigrationMissingMappingModelError = 134140,
    NSMigrationManagerSourceStoreError = 134150,
    NSMigrationManagerDestinationStoreError = 134160,
    NSEntityMigrationPolicyError = 134170,
    NSInferredMappingModelError = 134190,
    NSExternalRecordImportError = 134200,
    NSCoreDataError = 134060,
    NSSQLiteError = 134180,
};
