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
#import <AddressBook/ABAddressBook.h>
#import <CoreFoundation/CFArray.h>
#import <Foundation/NSObjCRuntime.h>

ADDRESSBOOK_EXPORT ABRecordRef ABAddressBookCopyDefaultSource(ABAddressBookRef addressBook) STUB_METHOD;
ADDRESSBOOK_EXPORT ABRecordRef ABAddressBookGetSourceWithRecordID(ABAddressBookRef addressBook, ABRecordID sourceID) STUB_METHOD;
ADDRESSBOOK_EXPORT CFArrayRef ABAddressBookCopyArrayOfAllSources(ABAddressBookRef addressBook) STUB_METHOD;

#define kABSourceTypeSearchableMask 0x01000000

typedef NS_OPTIONS(int, ABSourceType) {
    kABSourceTypeLocal = 0x0,
    kABSourceTypeExchange = 0x1,
    kABSourceTypeExchangeGAL = kABSourceTypeExchange | kABSourceTypeSearchableMask,
    kABSourceTypeMobileMe = 0x2,
    kABSourceTypeLDAP = 0x3 | kABSourceTypeSearchableMask,
    kABSourceTypeCardDAV = 0x4,
    kABSourceTypeCardDAVSearch = kABSourceTypeCardDAV | kABSourceTypeSearchableMask,
};

ADDRESSBOOK_EXPORT const ABPropertyID kABSourceNameProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABSourceTypeProperty;
