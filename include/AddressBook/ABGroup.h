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

#import <AddressBook/AddressBookExport.h>
#import <AddressBook/ABRecord.h>
#import <CoreFoundation/CFArray.h>
#import <AddressBook/ABPerson.h>
#import <CoreFoundation/CFError.h>
#import <AddressBook/ABAddressBook.h>

ADDRESSBOOK_EXPORT ABRecordRef ABGroupCreate() STUB_METHOD;
ADDRESSBOOK_EXPORT ABRecordRef ABGroupCreateInSource(ABRecordRef source) STUB_METHOD;
ADDRESSBOOK_EXPORT CFArrayRef ABGroupCopyArrayOfAllMembers(ABRecordRef group) STUB_METHOD;
ADDRESSBOOK_EXPORT CFArrayRef ABGroupCopyArrayOfAllMembersWithSortOrdering(ABRecordRef group,
                                                                           ABPersonSortOrdering sortOrdering) STUB_METHOD;

ADDRESSBOOK_EXPORT bool ABGroupAddMember(ABRecordRef group, ABRecordRef person, CFErrorRef* error) STUB_METHOD;
ADDRESSBOOK_EXPORT bool ABGroupRemoveMember(ABRecordRef group, ABRecordRef member, CFErrorRef* error) STUB_METHOD;
ADDRESSBOOK_EXPORT ABRecordRef ABAddressBookGetGroupWithRecordID(ABAddressBookRef addressBook, ABRecordID recordID) STUB_METHOD;
ADDRESSBOOK_EXPORT CFIndex ABAddressBookGetGroupCount(ABAddressBookRef addressBook) STUB_METHOD;
ADDRESSBOOK_EXPORT CFArrayRef ABAddressBookCopyArrayOfAllGroups(ABAddressBookRef addressBook) STUB_METHOD;
ADDRESSBOOK_EXPORT CFArrayRef ABAddressBookCopyArrayOfAllGroupsInSource(ABAddressBookRef addressBook, ABRecordRef source) STUB_METHOD;
ADDRESSBOOK_EXPORT ABRecordRef ABGroupCopySource(ABRecordRef group) STUB_METHOD;
ADDRESSBOOK_EXPORT const int kABGroupNameProperty;
