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

// WindowsApplicationModelContactsProvider.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WACPContactRemovedEventArgs, WACPContactPickerUI;
@protocol WACPIContactRemovedEventArgs
, WACPIContactPickerUI, WACPIContactPickerUI2;

// Windows.ApplicationModel.Contacts.Provider.AddContactResult
enum _WACPAddContactResult {
    WACPAddContactResultAdded = 0,
    WACPAddContactResultAlreadyAdded = 1,
    WACPAddContactResultUnavailable = 2,
};
typedef unsigned WACPAddContactResult;

#include "WindowsFoundationCollections.h"
#include "WindowsApplicationModelContacts.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Contacts.Provider.ContactRemovedEventArgs
#ifndef __WACPContactRemovedEventArgs_DEFINED__
#define __WACPContactRemovedEventArgs_DEFINED__

WINRT_EXPORT
@interface WACPContactRemovedEventArgs : RTObject
@property (readonly) NSString* id;
@end

#endif // __WACPContactRemovedEventArgs_DEFINED__

// Windows.ApplicationModel.Contacts.Provider.ContactPickerUI
#ifndef __WACPContactPickerUI_DEFINED__
#define __WACPContactPickerUI_DEFINED__

WINRT_EXPORT
@interface WACPContactPickerUI : RTObject
@property (readonly) NSArray* desiredFields;
@property (readonly) WACContactSelectionMode selectionMode;
@property (readonly) NSMutableArray* desiredFieldsWithContactFieldType;
- (EventRegistrationToken)addContactRemovedEvent:(void (^)(WACPContactPickerUI*, WACPContactRemovedEventArgs*))del;
- (void)removeContactRemovedEvent:(EventRegistrationToken)tok;
- (WACPAddContactResult)addContact:(NSString*)id contact:(WACContact*)contact;
- (void)removeContact:(NSString*)id;
- (BOOL)containsContact:(NSString*)id;
- (WACPAddContactResult)addContact:(WACContact*)contact;
@end

#endif // __WACPContactPickerUI_DEFINED__
