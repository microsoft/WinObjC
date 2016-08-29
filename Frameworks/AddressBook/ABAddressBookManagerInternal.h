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
#import <AddressBook/ABRecord.h>

@interface _ABAddressBookManager : NSObject

@property WACContactStore* contactStore;
- (NSArray*)getListOfContacts;
- (NSArray*)getListOfModifiableContacts;
- (bool)addContact:(ABRecordRef)record error:(CFErrorRef*)error;
- (bool)removeContact:(ABRecordRef)record error:(CFErrorRef*)error;
- (void)modifyContact:(ABRecordRef)record;
- (bool)hasUnsavedChanges;
- (void)revert;
- (bool)save;
@end

@interface __ABContactOperation : NSObject

@property BOOL shouldDelete;
@property WACContact* contact;
- (id)initWithContact:(WACContact*)contact shouldDelete:(BOOL)shouldDelete;

@end