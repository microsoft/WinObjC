//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import "ABAddressBookManagerInternal.h"
#import "ABContactInternal.h"
#import "UWP/WindowsApplicationModelContacts.h"

@implementation __ABContactOperation

- (id)initWithContact:(WACContact*)contact shouldDelete:(BOOL)shouldDelete {
    if (self = [super init]) {
        self.shouldDelete = shouldDelete;
        self.contact = contact;
    }

    return self;
}

@end

static void _setError(CFErrorRef* error, NSString* message) {
    if (error) {
        NSDictionary* userInfo = @{
            NSLocalizedDescriptionKey : NSLocalizedString(@"Error updating AddressBook.\n", nil),
            NSLocalizedFailureReasonErrorKey : NSLocalizedString(message, nil)
        };
        *error = (__bridge_retained CFErrorRef)[NSError errorWithDomain:(__bridge NSString*)ABAddressBookErrorDomain
                                                                   code:kABOperationNotPermittedByStoreError
                                                               userInfo:userInfo];
    }
}

static void _copyWrappedContacts(NSArray* /* WACContact* */ source,
                                 NSMutableArray* /* _ABContact* */ destination,
                                 ABRecordContactType type,
                                 ABRecordRef manager) {
    for (WACContact* contact in source) {
        _ABContact* wrappedContact = [[_ABContact alloc] initWithContact:contact andType:type];
        wrappedContact.manager = manager;
        [destination addObject:wrappedContact];
    }
}

@implementation _ABAddressBookManager {
    NSMutableSet<WACContact*>* _toAdd;
    NSMutableDictionary<NSString*, __ABContactOperation*>* _operations;
    WACContactStore* _writableStore;
    WACContactList* _contactList;
}

- (id)init {
    self = [super init];
    if (self) {
        _toAdd = [[NSMutableSet alloc] init];
        _operations = [[NSMutableDictionary alloc] init];

        __block WACContactStore* result = nil;
        __block BOOL failed = YES;
        dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);

        // Get the contact store for contacts that are read-only.
        [WACContactManager requestStoreAsyncWithAccessType:WACContactStoreAccessTypeAllContactsReadOnly
            success:^(WACContactStore* success) {
                result = success;
                failed = NO;
                dispatch_semaphore_signal(semaphore);
            }
            failure:^(NSError* failure) {
                failed = YES;
                dispatch_semaphore_signal(semaphore);
            }];

        // Wait until async method completes.
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);

        if (failed) {
            dispatch_release(semaphore);
            return nil;
        } else {
            self.contactStore = result;
        }

        // Get the contact store for the user's app (which has read-write access).
        [WACContactManager requestStoreAsyncWithAccessType:WACContactStoreAccessTypeAppContactsReadWrite
            success:^(WACContactStore* success) {
                result = success;
                failed = NO;
                dispatch_semaphore_signal(semaphore);
            }
            failure:^(NSError* failure) {
                failed = YES;
                dispatch_semaphore_signal(semaphore);
            }];

        // Wait until async method completes.
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);

        if (failed) {
            dispatch_release(semaphore);
            return nil;
        } else {
            _writableStore = result;
        }

        __block WACContactList* list = nil;
        __block BOOL shouldCreateList = NO;

        // Get the contact list associated with the user's app for adding/removing contacts.
        // If no such list exists yet, create a new one.
        [_writableStore findContactListsAsyncWithSuccess:^(NSArray* success) {
            if ([success count] == 0) {
                shouldCreateList = YES;
            } else {
                list = success[0];
                shouldCreateList = NO;
            }
            failed = NO;
            dispatch_semaphore_signal(semaphore);
        }
            failure:^(NSError* failure) {
                failed = YES;
                dispatch_semaphore_signal(semaphore);
            }];

        // Wait until async method completes.
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);

        if (failed) {
            dispatch_release(semaphore);
            return nil;
        }

        if (shouldCreateList) {
            [_writableStore createContactListAsync:@"ABAddressBook"
                success:^(WACContactList* success) {
                    list = success;
                    failed = NO;
                    dispatch_semaphore_signal(semaphore);
                }

                failure:^(NSError* failure) {
                    failed = YES;
                    dispatch_semaphore_signal(semaphore);
                }];

            // Wait until async method completes.
            dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
        }

        dispatch_release(semaphore);

        if (failed) {
            return nil;
        } else {
            _contactList = list;
        }
    }

    return self;
}

- (NSArray*)getListOfContacts {
    __block NSMutableArray* result = nil;
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);

    [self.contactStore findContactsAsyncWithSuccess:^(NSArray* success) {
        result = [NSMutableArray arrayWithCapacity:[success count]];

        // Copy over the contacts wrapped in _ABContacts.
        _copyWrappedContacts(success, result, kAddressBookReadOnlyContact, (__bridge ABRecordRef)self);

        dispatch_semaphore_signal(semaphore);
    }
        failure:^(NSError* failure) {
            // In the failure case, result will be nil.
            dispatch_semaphore_signal(semaphore);
        }];

    // Wait until async method completes.
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    dispatch_release(semaphore);

    return result;
}

- (NSArray*)getListOfModifiableContacts {
    NSMutableArray* result = [[NSMutableArray alloc] init];
    WACContactReader* reader = [_contactList getContactReader];
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);

    __block BOOL shouldContinue = YES;
    while (shouldContinue) {
        // Keep reading batches until the batch is empty.
        [reader readBatchAsyncWithSuccess:^(WACContactBatch* success) {
            if ([success.contacts count] == 0) {
                shouldContinue = NO;
            } else {
                shouldContinue = YES;
                _copyWrappedContacts(success.contacts, result, kAddressBookReadWriteContact, (__bridge ABRecordRef)self);
            }
            dispatch_semaphore_signal(semaphore);
        }

            failure:^(NSError* error) {
                shouldContinue = NO;
                dispatch_semaphore_signal(semaphore);
            }];

        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    }

    dispatch_release(semaphore);
    return result;
}

- (bool)addContact:(ABRecordRef)record error:(CFErrorRef*)error {
    _ABContact* contact = (__bridge _ABContact*)record;

    switch (contact.type) {
        case kAddressBookNewContact: {
            // New contacts can't be added twice.
            if ([_toAdd containsObject:contact.contact]) {
                _setError(error, @"This contact has already been added.\n");
                return false;
            }

            [_toAdd addObject:contact.contact];
            return true;
        }
        case kAddressBookReadWriteContact: {
            __ABContactOperation* operation = _operations[contact.contact.id];

            // A read-write contact can only be added if it was previously deleted,
            // so ensure that the current operation does exist and that it is marked
            // for deletion.
            if (operation == nil || (!operation.shouldDelete)) {
                _setError(error, @"This contact already exists in the AddressBook.\n");
                return false;
            }

            operation.shouldDelete = NO;
            return true;
        }
        case kAddressBookReadOnlyContact:
        default:
            _setError(error, @"This contact cannot be added to the AddressBook.\n");
            return false;
    }
}

- (bool)removeContact:(ABRecordRef)record error:(CFErrorRef*)error {
    _ABContact* contact = (__bridge _ABContact*)record;

    switch (contact.type) {
        case kAddressBookNewContact: {
            // New contacts can only be removed if they were
            // previously marked to be added.
            if ([_toAdd containsObject:contact.contact]) {
                [_toAdd removeObject:contact.contact];
                return true;
            }

            _setError(error, @"Only existing contacts can be removed from the AddressBook.\n");
            return false;
        }
        case kAddressBookReadWriteContact: {
            __ABContactOperation* operation = _operations[contact.contact.id];

            // A read/write contact can be deleted in 2 cases: if no operation was associated,
            // or if the associated operation is that it has been modified. In the case that
            // it is already marked to delete, deleting twice doesn't make sense.
            if (operation == nil) {
                operation = [[__ABContactOperation alloc] initWithContact:contact.contact shouldDelete:YES];
                _operations[contact.contact.id] = operation;
                return true;
            } else if (operation.shouldDelete) {
                _setError(error, @"This contact has already been deleted.\n");
                return false;
            } else {
                operation.shouldDelete = YES;
                return true;
            }
        }
        case kAddressBookReadOnlyContact:
        default:
            _setError(error,
                      @"Read-only contacts cannot be deleted. Use ABAddressBookCopyArrayOfAllUserAppPeople to get contacts that can "
                      @"be deleted.\n");
            return false;
    }
}

- (void)modifyContact:(ABRecordRef)record {
    _ABContact* contact = (__bridge _ABContact*)record;
    __ABContactOperation* operation = _operations[contact.contact.id];

    // If there was no operation previously associated with this record, then
    // set it to be modified. The other two cases are that the contact was
    // already to be modified (in which case, we don't need to do anything),
    // or that the contact is marked to be deleted -- in this case, since
    // it is to be deleted, there is no need to worry about any modifications.
    if (operation == nil) {
        operation = [[__ABContactOperation alloc] initWithContact:contact.contact shouldDelete:NO];
        _operations[contact.contact.id] = operation;
    }
}

- (bool)hasUnsavedChanges {
    return _toAdd.count + _operations.count > 0;
}

- (void)revert {
    [_toAdd removeAllObjects];
    [_operations removeAllObjects];
}

- (bool)save {
    // TODO #942: When the projections for WACContactList's saveContactAsync and deleteContactAsync
    // get success/fail blocks, use a dispatch_group_t to spawn off all async calls at the same
    // time rather than the blocking WFIASyncAction getResults, and return false in the case
    // that the fail block is called (rather than just returning true always).

    // Go through all contacts that were newly created and need to be added,
    // and save them to this app's contact list.
    for (WACContact* contact in _toAdd) {
        RTObject<WFIAsyncAction>* asyncAction = [_contactList saveContactAsync:contact];
        [asyncAction getResults];
    }

    // Go through all contacts that were pre-existing and need to either be
    // saved due to modification, or need to be deleted due to be removed.
    for (NSString* key in _operations) {
        __ABContactOperation* operation = _operations[key];
        BOOL shouldDelete = operation.shouldDelete;
        WACContact* contact = operation.contact;
        if (shouldDelete) {
            RTObject<WFIAsyncAction>* asyncAction = [_contactList deleteContactAsync:contact];
            [asyncAction getResults];
        } else {
            RTObject<WFIAsyncAction>* asyncAction = [_contactList saveContactAsync:contact];
            [asyncAction getResults];
        }
    }

    [self revert];
    return true;
}

@end