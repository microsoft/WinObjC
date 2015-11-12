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

#ifndef _COREDATAERRORS_H_
#define _COREDATAERRORS_H_

#import <Foundation/NSString.h>
#import <StarboardExport.h>

enum {
    NSPersistentStoreInvalidTypeError = 134000,
    NSPersistentStoreTypeMismatchError = 134010,
    NSPersistentStoreIncompatibleSchemaError = 134020,
    NSPersistentStoreSaveError = 134030,
    NSPersistentStoreIncompleteSaveError = 134040,
    NSPersistentStoreOperationError = 134070,
    NSPersistentStoreOpenError = 134080,
    NSPersistentStoreTimeoutError = 134090,
    NSPersistentStoreIncompatibleVersionHashError = 134100,
    NSManagedObjectContextLockingError = 132000,
    NSPersistentStoreCoordinatorLockingError = 132010,
    NSManagedObjectReferentialIntegrityError = 133000,
    NSManagedObjectExternalRelationshipError = 133010,
    NSManagedObjectMergeError = 133020,
    NSMigrationError = 134110,
    NSMigrationCancelledError = 134120,
    NSMigrationMissingSourceModelError = 134130,
    NSMigrationMissingMappingModelError = 134140,
    NSMigrationManagerSourceStoreError = 134150,
    NSMigrationManagerDestinationStoreError = 134160,
    NSEntityMigrationPolicyError = 134170,
    NSInferredMappingModelError = 134190,
    NSExternalRecordImportError = 134200,
};

SB_EXPORT NSString* const NSDetailedErrorsKey;
SB_EXPORT NSString* const NSValidationObjectErrorKey;
SB_EXPORT NSString* const NSValidationKeyErrorKey;
SB_EXPORT NSString* const NSValidationPredicateErrorKey;
SB_EXPORT NSString* const NSValidationValueErrorKey;
SB_EXPORT NSString* const NSAffectedStoresErrorKey;
SB_EXPORT NSString* const NSAffectedObjectsErrorKey;
SB_EXPORT NSString* const NSPersistentStoreSaveConflictsErrorKey;

#endif /* _COREDATAERRORS_H_ */