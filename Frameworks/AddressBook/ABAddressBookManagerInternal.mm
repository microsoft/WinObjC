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

#import <unordered_set>
#import <unordered_map>
#import <utility>
#import "ABAddressBookManagerInternal.h"
#import "ABContactInternal.h"
#import "CppWinRTHelpers.h"

using namespace winrt::Windows::ApplicationModel::Contacts;
namespace WF = winrt::Windows::Foundation;
namespace WFC = winrt::Windows::Foundation::Collections;

@implementation __ABContactOperation {
    TrivialDefaultConstructor<Contact> _contact;
}

- (id)initWithContact:(const Contact&)contact shouldDelete:(BOOL)shouldDelete {
    if (self = [super init]) {
        self.shouldDelete = shouldDelete;
        self.contact = contact;
    }

    return self;
}

@dynamic contact;

- (Contact)contact {
    return _contact;
}

- (void)setContact:(Contact)contact {
    _contact = std::move(contact);
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

static void _copyWrappedContacts(const WFC::IVectorView<Contact>& source,
                                 NSMutableArray* /* _ABContact* */ destination,
                                 ABRecordContactType type,
                                 ABRecordRef manager) {
    for (const Contact& contact : source) {
        _ABContact* wrappedContact = [[_ABContact alloc] initWithContact:contact andType:type];
        wrappedContact.manager = manager;
        [destination addObject:wrappedContact];
    }
}

@implementation _ABAddressBookManager {
    std::unordered_set<Contact> _toAdd;
    std::unordered_map<winrt::hstring, __ABContactOperation*> _operations;
    TrivialDefaultConstructor<ContactStore> _writableStore;
    TrivialDefaultConstructor<ContactList> _contactList;
    TrivialDefaultConstructor<ContactStore> _contactStore;
}

- (id)init {
    self = [super init];
    if (self) {
        ContactStore result = nullptr;
        BOOL failed = YES;
        dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);

        // Get the contact store for contacts that are read-only.
        WF::IAsyncOperation<ContactStore> async =
            ContactManager::RequestStoreAsync(ContactStoreAccessType::AllContactsReadOnly);

        async.Completed(objcwinrt::callback([&result, &failed, semaphore] (const WF::IAsyncOperation<ContactStore>& success, WF::AsyncStatus status) {
            if (status == WF::AsyncStatus::Completed) {
                result = success.GetResults();
                failed = NO;
            }

            dispatch_semaphore_signal(semaphore);
        }));

        // Wait until async method completes.
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);

        if (failed) {
            dispatch_release(semaphore);
            return nil;
        } else {
            self.contactStore = result;
        }

        // Get the contact store for the user's app (which has read-write access).
        async = ContactManager::RequestStoreAsync(ContactStoreAccessType::AppContactsReadWrite);

        async.Completed(objcwinrt::callback([&result, &failed, semaphore] (const WF::IAsyncOperation<ContactStore>& success, WF::AsyncStatus status) {
            if (status == WF::AsyncStatus::Completed) {
                result = success.GetResults();
                failed = NO;
            } else {
                failed = YES;
            }

            dispatch_semaphore_signal(semaphore);
        }));

        // Wait until async method completes.
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);

        if (failed) {
            dispatch_release(semaphore);
            return nil;
        } else {
            _writableStore = result;
        }

        ContactList list = nullptr;
        BOOL shouldCreateList = NO;

        // Get the contact list associated with the user's app for adding/removing contacts.
        // If no such list exists yet, create a new one.
        WF::IAsyncOperation<WFC::IVectorView<ContactList>> contactsAsync = _writableStore.FindContactListsAsync();

        contactsAsync.Completed(objcwinrt::callback(
            [&list, &failed, &shouldCreateList, semaphore] (const WF::IAsyncOperation<WFC::IVectorView<ContactList>>& success, WF::AsyncStatus status) {
                if (status == WF::AsyncStatus::Completed) {
                    WFC::IVectorView<ContactList> contactList = success.GetResults();

                    if (contactList.Size() == 0) {
                        shouldCreateList = YES;
                    } else {
                        list = contactList.GetAt(0);
                        shouldCreateList = NO;
                    }

                    failed = NO;
                } else {
                    failed = YES;
                }

                dispatch_semaphore_signal(semaphore);
            }));

        // Wait until async method completes.
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);

        if (failed) {
            dispatch_release(semaphore);
            return nil;
        }

        if (shouldCreateList) {
            WF::IAsyncOperation<ContactList> listAsync = _writableStore.CreateContactListAsync(L"ABAddressBook");

            listAsync.Completed(objcwinrt::callback([&list, &failed, semaphore] (const WF::IAsyncOperation<ContactList>& success, WF::AsyncStatus status) {
                if (status == WF::AsyncStatus::Completed) {
                    list = success.GetResults();
                    failed = NO;
                } else {
                    failed = YES;
                }

                dispatch_semaphore_signal(semaphore);
            }));

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

@dynamic contactStore;

- (ContactStore)contactStore {
    return _contactStore;
}

- (void)setContactStore:(ContactStore)store {
    _contactStore = std::move(store);
}

- (NSArray*)getListOfContacts {
    NSMutableArray* result = nil;
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);

    WF::IAsyncOperation<WFC::IVectorView<Contact>> async = self.contactStore.FindContactsAsync();

    async.Completed(objcwinrt::callback([&result, semaphore, self] (const WF::IAsyncOperation<WFC::IVectorView<Contact>>& success, WF::AsyncStatus status) {
        if (status == WF::AsyncStatus::Completed) {
            WFC::IVectorView<Contact> contacts = success.GetResults();

            result = [NSMutableArray arrayWithCapacity:contacts.Size()];

            // Copy over the contacts wrapped in _ABContacts.
            _copyWrappedContacts(contacts, result, kAddressBookReadOnlyContact, (__bridge ABRecordRef)self);
        } else {
            // In the failure case, result will be nil
        }

        dispatch_semaphore_signal(semaphore);
    }));

    // Wait until async method completes.
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    dispatch_release(semaphore);

    return result;
}

- (NSArray*)getListOfModifiableContacts {
    NSMutableArray* result = [[NSMutableArray alloc] init];
    ContactReader reader = _contactList.GetContactReader();
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);

    BOOL shouldContinue = YES;
    while (shouldContinue) {
        // Keep reading batches until the batch is empty.
        WF::IAsyncOperation<ContactBatch> async = reader.ReadBatchAsync();

        async.Completed(objcwinrt::callback([&shouldContinue, result, semaphore, self] (const WF::IAsyncOperation<ContactBatch>& success, WF::AsyncStatus status) {
            if (status == WF::AsyncStatus::Completed) {
                ContactBatch batch = success.GetResults();

                if (batch.Contacts().Size() == 0) {
                    shouldContinue = NO;
                } else {
                    shouldContinue = YES;
                    _copyWrappedContacts(batch.Contacts(), result, kAddressBookReadWriteContact, (__bridge ABRecordRef)self);
                }
            } else {
                shouldContinue = NO;
            }

            dispatch_semaphore_signal(semaphore);
        }));

        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    }

    dispatch_release(semaphore);
    return result;
}

- (bool)addContact:(ABRecordRef)record error:(CFErrorRef*)error {
    _ABContact* contact = (__bridge _ABContact*)record;

    switch (contact.type) {
        case kAddressBookNewContact: {
            std::pair<std::unordered_set<Contact>::iterator, bool> result = _toAdd.insert(contact.contact);
            if (!result.second) {
                // New contacts can't be added twice.
                _setError(error, @"This contact has already been added.\n");
            }

            return result.second;
        }
        case kAddressBookReadWriteContact: {
            __ABContactOperation* operation = _operations[contact.contact.Id()];

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
            std::unordered_set<Contact>::iterator it = _toAdd.find(contact.contact);

            // New contacts can only be removed if they were
            // previously marked to be added.
            if (it == _toAdd.end()) {
                _setError(error, @"Only existing contacts can be removed from the AddressBook.\n");
                return false;
            }

            _toAdd.erase(it);
            return true;
        }
        case kAddressBookReadWriteContact: {
            __ABContactOperation* operation = _operations[contact.contact.Id()];

            // A read/write contact can be deleted in 2 cases: if no operation was associated,
            // or if the associated operation is that it has been modified. In the case that
            // it is already marked to delete, deleting twice doesn't make sense.
            if (operation == nil) {
                operation = [[__ABContactOperation alloc] initWithContact:contact.contact shouldDelete:YES];
                _operations[contact.contact.Id()] = operation;
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
    __ABContactOperation* operation = _operations[contact.contact.Id()];

    // If there was no operation previously associated with this record, then
    // set it to be modified. The other two cases are that the contact was
    // already to be modified (in which case, we don't need to do anything),
    // or that the contact is marked to be deleted -- in this case, since
    // it is to be deleted, there is no need to worry about any modifications.
    if (operation == nil) {
        operation = [[__ABContactOperation alloc] initWithContact:contact.contact shouldDelete:NO];
        _operations[contact.contact.Id()] = operation;
    }
}

- (bool)hasUnsavedChanges {
    return _toAdd.size() + _operations.size() > 0;
}

- (void)revert {
    _toAdd.clear();
    _operations.clear();
}

- (bool)save {
    // TODO #942: Use a dispatch_group_t to spawn off all async calls at the same
    // time rather than the blocking IASyncAction getResults, and return false in the case
    // that the async action failed (rather than just returning true always).

    // Go through all contacts that were newly created and need to be added,
    // and save them to this app's contact list.
    for (const Contact& contact : _toAdd) {
        _contactList.SaveContactAsync(contact).GetResults();
    }

    // Go through all contacts that were pre-existing and need to either be
    // saved due to modification, or need to be deleted due to be removed.
    for (const std::pair<const winrt::hstring, __ABContactOperation*>& operation : _operations) {
        BOOL shouldDelete = operation.second.shouldDelete;
        Contact contact = operation.second.contact;
        if (shouldDelete) {
            _contactList.DeleteContactAsync(contact).GetResults();
        } else {
            _contactList.SaveContactAsync(contact).GetResults();
        }
    }

    [self revert];
    return true;
}

@end