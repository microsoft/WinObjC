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

#pragma once

#import "ABRecordInternal.h"
#import <AddressBook/ABAddressBook.h>

#include "COMIncludes.h"
#import <winrt/Windows.ApplicationModel.Contacts.h>
#include "COMIncludes_End.h"

typedef enum ABRecordContactType {
    kAddressBookNewContact = 0,
    kAddressBookReadOnlyContact,
    kAddressBookReadWriteContact
} ABRecordContactType;

@interface _ABContact : _ABRecord

@property winrt::Windows::ApplicationModel::Contacts::Contact contact;
@property ABAddressBookRef manager;
@property (readonly) ABRecordContactType type;
- (id)initWithContact:(const winrt::Windows::ApplicationModel::Contacts::Contact&)contact andType:(ABRecordContactType)type;

@end