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

#import "UWP/WindowsApplicationModelContacts.h"
#import "ABRecordInternal.h"
#import <AddressBook/ABAddressBook.h>

typedef enum ABRecordContactType {
    kAddressBookNewContact = 0,
    kAddressBookReadOnlyContact,
    kAddressBookReadWriteContact
} ABRecordContactType;

@interface _ABContact : _ABRecord

@property WACContact* contact;
@property ABAddressBookRef manager;
@property (readonly) ABRecordContactType type;
- (id)initWithContact:(WACContact*)contact andType:(ABRecordContactType)type;

@end